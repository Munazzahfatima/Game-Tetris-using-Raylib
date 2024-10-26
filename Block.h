#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"
class Block {
public:
	Block();
	void Draw(int offsetX,int offsetY);
	void Move(int, int);
	std::vector<Position>GetCellPositions();
	int id;
	std::map<int, std::vector<Position>>cells;
	void Rotate();
	void UndoRotation();

private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int rowOffset;
	int columnOffset;
};