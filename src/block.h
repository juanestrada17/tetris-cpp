#pragma once 
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
    Block();
    // Represent each unique block
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    void Rotate();
    void UndoRotation();
    int id;
    std::vector <Position> GetCellPositions();
    // position of block using a map of vectors. <std::pair<int, int>
    std::map<int, std::vector<Position>> cells;
private:
    int cellSize; 
    int rotationState;
    int rowOffset;
    int columnOffset;
    std::vector<Color> colors;
};