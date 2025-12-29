#include "player.h"
#include "map.h"
#include <math.h>

void InitPlayer(Player *player)
{
    player->position = (Vector2){60, 60};
    player->direction = (Vector2){1, 0};
    player->radius = 10.0f;
    player->color = RED;
    player->speed = 3.0f;
    player->rotSpeed = 0.05f;
    player->plane = (Vector2){0.0f, 0.66f};
}

void DrawPlayer(Player *player)
{

    DrawCircleV(player->position, player->radius, player->color);

    Vector2 lineEnd = {
        player->position.x + player->direction.x * 20,
        player->position.y + player->direction.y * 20};
    DrawLineV(player->position, lineEnd, YELLOW);

    DrawCircleV(player->position, 2, WHITE);
}


void UpdatePlayer(Player *player)
{
    extern int map[20][20];
    float delta = GetFrameTime();
    float moveSpeed = player->speed * delta * 60;
    // if (IsKeyDown(KEY_W))
    // {
    //     Vector2 newPos = player->position;
    //     newPos.x += player->direction.x * moveSpeed;
    //     newPos.y += player->direction.y * moveSpeed;

    //     int mapX = (int)(newPos.x / 30);
    //     int mapY = (int)(newPos.y / 30);

    //     if (!IsWall(mapX, mapY))
    //     {
    //         player->position = newPos;
    //     }
    // }
    if (IsKeyDown(KEY_W))
{
    float desiredMoveX = player->direction.x * moveSpeed;
    float desiredMoveY = player->direction.y * moveSpeed;
    
    Vector2 newPos = player->position;
    newPos.x += desiredMoveX;
    newPos.y += desiredMoveY;
    
    int mapX = (int)(newPos.x / 30);
    int mapY = (int)(newPos.y / 30);
    
    int canMoveFull = 1; 
    
    if (mapX < 0 || mapX >= 20 || mapY < 0 || mapY >= 20)
    {
        canMoveFull = 0;
    }
    else if (map[mapY][mapX] > 0)
    {
        canMoveFull = 0;
    }
    
    if (canMoveFull == 1)
    {
        player->position = newPos;
    }
    else
    {
        Vector2 tryX = player->position;
        tryX.x += desiredMoveX;
        
        int mapX_x = (int)(tryX.x / 30);
        int mapY_x = (int)(tryX.y / 30);
        
        int canMoveX = 1;
        
        if (mapX_x < 0 || mapX_x >= 20 || mapY_x < 0 || mapY_x >= 20)
        {
            canMoveX = 0;
        }
        else if (map[mapY_x][mapX_x] > 0)
        {
            canMoveX = 0;
        }
        
        if (canMoveX == 1)
        {
            player->position.x = tryX.x;
        }
        
        Vector2 tryY = player->position;
        tryY.y += desiredMoveY;
        
        int mapX_y = (int)(tryY.x / 30);
        int mapY_y = (int)(tryY.y / 30);
        
        int canMoveY = 1;
        
        if (mapX_y < 0 || mapX_y >= 20 || mapY_y < 0 || mapY_y >= 20)
        {
            canMoveY = 0;
        }
        else if (map[mapY_y][mapX_y] > 0)
        {
            canMoveY = 0;
        }
        
        if (canMoveY == 1)
        {
            player->position.y = tryY.y;
        }
    }
}

    if (IsKeyDown(KEY_S))
    {
        Vector2 newPos = player->position;
        newPos.x -= player->direction.x * moveSpeed;
        newPos.y -= player->direction.y * moveSpeed;

        int mapX = (int)(newPos.x / 30);
        int mapY = (int)((newPos.y) / 30);

        if (!IsWall(mapX, mapY))
        {
            player->position = newPos;
        }
    }

    if (IsKeyDown(KEY_D))
    {
        Vector2 leftDir = {-player->direction.y, player->direction.x};

        Vector2 newPos = player->position;
        newPos.x += leftDir.x * moveSpeed;
        newPos.y += leftDir.y * moveSpeed;

        int mapX = (int)(newPos.x / 30);
        int mapY = (int)(newPos.y / 30);

        if (!IsWall(mapX, mapY))
        {
            player->position = newPos;
        }
    }

    if (IsKeyDown(KEY_A))
    {
        Vector2 rightDir = {player->direction.y, -player->direction.x};

        Vector2 newPos = player->position;
        newPos.x += rightDir.x * moveSpeed;
        newPos.y += rightDir.y * moveSpeed;

        int mapX = (int)(newPos.x / 30);
        int mapY = (int)(newPos.y / 30);

        if (!IsWall(mapX, mapY))
        {
            player->position = newPos;
        }
    }
    float actualRotSpeed = player->rotSpeed * delta * 60.0f;

    if (IsKeyDown(KEY_RIGHT))
    {
        UpdateDirection(player, actualRotSpeed);
    }
    if (IsKeyDown(KEY_LEFT))
    {
        UpdateDirection(player, -actualRotSpeed);
    }
}
void UpdateDirection(Player *player, float angle)
{

    float oldDirX = player->direction.x;
    float oldPlaneX = player->plane.x;
    player->direction.x = player->direction.x * cos(angle) - player->direction.y * sin(angle);
    player->direction.y = oldDirX * sin(angle) + player->direction.y * cos(angle);

    player->plane.x = player->plane.x * cos(angle) - player->plane.y * sin(angle);
    player->plane.y = oldPlaneX * sin(angle) + player->plane.y * cos(angle);
}