#pragma once
#include <vector>
#include <raylib.h>

class Grid {
public:
	Grid();
	int grid[20][10];
	void Print()const;
	void Init();
	void Draw();
	bool IsCellOutside(int, int );
	bool IsCellEmpty(int, int);
	int ClearFullRows();

private:
	bool IsRowFull(int)const;
	void ClearRow(int) const;
	void MoveRowDown(int,int);
	int numRows;
	int numCols;
	int cellSize;  
	std::vector<Color> colors;
	
};