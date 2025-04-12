#include <iostream>
#include <raylib.h>
#include "game.h"
#include "colors.h"

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

    // w / h 
    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    // Loading font
    Font font  = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

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
        // void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 165}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 455}, 38, 2, WHITE);
        }
        // void DrawRectangleRounded(Rectangle rec, float, roundness, int segments, Color color); 
        // rec = position and size
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
