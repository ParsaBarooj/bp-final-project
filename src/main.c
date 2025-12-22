#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

typedef enum
{
    VIEW_2D,
    VIEW_3D,
} ViewModes;

int main(void)
{
    InitWindow(600, 600, "game project");

    ViewModes currentView = VIEW_2D;

    SetTargetFPS(60);

    Player player1;
    InitPlayer(&player1);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_M))
        {
            currentView = (currentView == VIEW_2D) ? VIEW_3D : VIEW_2D;
        }
        
        UpdatePlayer(&player1);
        BeginDrawing();
        
        ClearBackground(BLACK);
        if (currentView == VIEW_2D)
        {
            
            DrawSimpleMap();
            
            DrawPlayer(&player1);
            
            EndDrawing();
        }
        else
        {
            Render3DView(&player1);
        }
        DrawText("کلید M فشرده شد!", 300, 300, 30, RED);
    }

    CloseWindow();

    return 0;
}