#include <iostream>
#include <raylib.h>
#include "game.h"

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
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
