#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    numRows= 20;
    numCols= 10;
    cellSize= 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()
{
    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print()
{
    for(int row=0; row < numRows; row ++)
    {
        for(int column=0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
};


void Grid::Draw()
{
    for(int row=0; row < numRows; row ++)
    {
        for(int column=0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            // DrawRectangle(x, y, w, h, color);
            // cellValue will be 0, using the first element in the vector.
            // + 1 and -1 to create some margin
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize -1 , cellSize -1, colors[cellValue]);
            
        }
    }
}