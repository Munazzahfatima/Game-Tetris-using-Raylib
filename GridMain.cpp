#include "GridMain.h"
#include <iostream>
#include "colors.h"
using namespace std;
Grid::Grid() {
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	Init();
	colors=GetCellColors();
}

void Grid::Init() {
	for (int rows= 0; rows <numRows; rows++)
	{
		for (int cols = 0; cols < numCols; cols++) {
			grid[rows][cols] = 0;
		}
	}
}

void Grid::Print() const {
	for (int rows = 0; rows < numRows; rows++)
	{
		for (int cols = 0; cols < numCols; cols++) {
			cout << grid[rows][cols] << " ";
		}
		cout << endl;
	}
}


void Grid::Draw() {
	for (int rows = 0; rows < numRows; rows++)
	{
		for (int cols = 0; cols < numCols; cols++) {
			int cellValue= grid[rows][cols] ;
			DrawRectangle(cols*cellSize + 11, rows*cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);
		}
		 
	}
}

bool Grid::IsCellOutside(int row, int colm)
{

	if (row >= 0 && row < numRows && colm >= 0 && colm < numCols) {
		return false;
	}
	else
		return true;
}

bool Grid::IsCellEmpty(int row, int colm)
{
	if (grid[row][colm] == 0) {
		return true;
	}
	return false;
}

int Grid::ClearFullRows(){
	int completed = 0;
	for (int row = (numRows - 1); row >= 0; row--) {
		if (IsRowFull(row)) {
			ClearRow(row);
			completed++;
		}
		else if (completed > 0) {
			MoveRowDown(row, completed);
		}
	}
	return completed;
}

bool Grid::IsRowFull(int row)const{
	for (int colm = 0; colm < numCols; colm++) {
		if (grid[row][colm] == 0) {
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row)const {
	for (int colm = 0; colm < numCols; colm++) {
		grid[row][colm] == 0;
	}
	
}

void Grid::MoveRowDown(int row, int numRows){
	for (int colm = 0; colm < numCols; colm++) {
		grid[row + numRows][colm] = grid[row][colm];
		grid[row][colm] = 0;
	}

}


