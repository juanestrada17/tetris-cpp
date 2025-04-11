#include <iostream>
#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0; 

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main(int, char**){

    Color darkBlue = {44, 44, 127, 255};
    // w / h 
    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    Game game = Game();

    while(!WindowShouldClose())
    {   
        BeginDrawing();
        game.HandleInput();
        
        // 200 miliseconds 
        if(EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
