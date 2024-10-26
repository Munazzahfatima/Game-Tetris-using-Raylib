#pragma once
#include "GridMain.h"
#include "allBlocks.cpp"
class Game {
public:
	Game();
	~Game();
	void Draw();
	void MoveBlockDown();
	void HandleInput();
	bool gameOver;
	int score;
	 
private:
	Grid grid;
	Block GetRandomBlock();
	std::vector<Block>GetAllBlocks();
	void MoveBlockLeft();
	void MoveBlockRight();
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int,int);
	std::vector<Block>blocks;
	Block currentBlock; 
	Block nextBlock;
	Sound rotateSound;
	Sound clearSound;
};