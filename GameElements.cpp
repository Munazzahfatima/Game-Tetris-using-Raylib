#include "GameElements.h"
#include <random>


Game::Game(){
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
	score = 0;
	InitAudioDevice();
	
	rotateSound = LoadSound("sounds/Sounds_rotate.mp3");
	clearSound = LoadSound("sounds/Sounds_clear.mp3");
}
Game::~Game() {
	UnloadSound(rotateSound);
	UnloadSound(clearSound);
	CloseAudioDevice();
}

Block Game::GetRandomBlock() {
	if (blocks.empty()) {
		blocks = GetAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

std::vector<Block>Game::GetAllBlocks() {
	return { IBlock(),JBlock(),TBlock(),ZBlock(),OBlock(),SBlock(),LBlock() };
}


void Game::Draw() {
	grid.Draw();
	currentBlock.Draw(11,11);
	switch (nextBlock.id) {
	case 3:
		nextBlock.Draw(310, 290);
		break;
	case 4:
		nextBlock.Draw(310, 280);
		break;
	default:
		nextBlock.Draw(320, 270);
		break;
	}
}

void Game::HandleInput() {
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0) {
		gameOver = false;
		Reset();
	}
	switch (keyPressed)
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		UpdateScore(0, 1);
		break;
	case KEY_UP:
		RotateBlock();
		break;
	}
}

void Game::MoveBlockLeft() {
	if (!gameOver) {
		currentBlock.Move(0, -1);
		if (IsBlockOutside() || BlockFits() == false)
			currentBlock.Move(0, 1);
	}
}
void Game::MoveBlockRight() {
	if (!gameOver) {
		currentBlock.Move(0, 1);
		if (IsBlockOutside() || BlockFits() == false)
			currentBlock.Move(0, -1);
	}
}
void Game::MoveBlockDown() {
	if (!gameOver) {
		currentBlock.Move(1, 0);
		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

bool Game::IsBlockOutside()
{
	std::vector<Position>tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		if (grid.IsCellOutside(item.row, item.column)) {
			return true;
		}
	}
	return false;
}

void Game::RotateBlock() {
	if (!gameOver) {
		currentBlock.Rotate();
		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.UndoRotation();
		}
		else {
			PlaySound(rotateSound);
		}
	}
}

void Game::LockBlock(){
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (BlockFits() == false) {
		gameOver = true;
	}
	nextBlock = GetRandomBlock();
	int rowscleared= grid.ClearFullRows();
	if (rowscleared > 0) {
		PlaySound(clearSound);
		UpdateScore(rowscleared, 0);
	}
	
}

bool Game::BlockFits()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		if (grid.IsCellEmpty(item.row, item.column) == false) {
			return false;
		}
	}
	return true;
}

void Game::Reset(){
	grid.Init();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints){
	switch (linesCleared) {
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default:
		break;

	}
	score += moveDownPoints;
}
