#include "raylib.h"
#include "map.h"
#include "player.h"

int main(void)
{
    InitWindow(600, 600, "game project");
    
    SetTargetFPS(60);
    
    Player player1;
    InitPlayer(&player1);
    
    while (!WindowShouldClose())
    {
        UpdatePlayer(&player1);
        UpdateDirection(&player1);
        BeginDrawing();

        ClearBackground(BLACK);

        
        DrawSimpleMap();

        DrawPlayer(&player1);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}