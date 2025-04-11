#pragma once 
#include <vector>
#include <map>
#include "position.h"

class Block
{
public:
    Block();
    // Represent each unique block
    void Draw();
    int id;
    // position of block using a map of vectors. <std::pair<int, int>
    std::map<int, std::vector<Position>> cells;
private:
    int cellSize; 
    int rotationState;
    std::vector<Color> colors;

};