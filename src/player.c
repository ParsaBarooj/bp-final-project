#include "player.h"
#include "map.h"

void InitPlayer(Player *player)
{
    player->position = (Vector2){60, 60};
    player->direction = (Vector2){1, 0};
    player->radius = 10.0f;
    player->color = RED;
    player->speed = 3.0f;
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

// void UpdatePlayer(Player *player){
//     Vector2 newPos = player->position;

//     int mapX = (int)newPos.x / 30;
//     int mapY = (int)newPos.y / 30;

//     if (!IsWall(mapX, mapY)) {
//         player->position = newPos;
//     }

//     if (IsKeyDown(KEY_W))
//     {
//         player->position.y -= player->speed;
//     }
//     if (IsKeyDown(KEY_S))
//     {
//         player->position.y += player->speed;
//     }
//     if (IsKeyDown(KEY_A))
//     {
//         player->position.x -= player->speed;
//     }
//     if (IsKeyDown(KEY_D))
//     {
//         player->position.x += player->speed;
//     }
// }
void UpdatePlayer(Player *player) {
    
    if (IsKeyDown(KEY_W)) {
        Vector2 newPos = player->position;
        newPos.y -= player->speed;
        
        int mapX = (int)(newPos.x / 30);
        int mapY = (int)((newPos.y) / 30);
        
        if (!IsWall(mapX, mapY)) {
            player->position = newPos;
        }
    }
    
    if (IsKeyDown(KEY_S)) {
        Vector2 newPos = player->position;
        newPos.y += player->speed;
        
        int mapX = (int)(newPos.x / 30);
        int mapY = (int)((newPos.y) / 30);
        
        if (!IsWall(mapX, mapY)) {
            player->position = newPos;
        }
    }
    
    if (IsKeyDown(KEY_A)) {
        Vector2 newPos = player->position;
        newPos.x -= player->speed;
        
        int mapX = (int)(newPos.x / 30);
        int mapY = (int)((newPos.y) / 30);
        
        if (!IsWall(mapX, mapY)) {
            player->position = newPos;
        }
    }
    
    if (IsKeyDown(KEY_D)) {
        Vector2 newPos = player->position;
        newPos.x += player->speed;
        
        int mapX = (int)(newPos.x / 30);
        int mapY = (int)((newPos.y) / 30);
        
        if (!IsWall(mapX, mapY)) {
            player->position = newPos;
        }
    }
    
}
void UpdateDirection(Player *player)
{
    if (IsKeyDown(KEY_UP))
    {
        if (IsKeyDown(KEY_RIGHT))
            player->direction = (Vector2){1, -1};
        else if (IsKeyDown(KEY_LEFT))
            player->direction = (Vector2){-1, -1};
        else
        {
            player->direction = (Vector2){0, -1};
        }
    }
    if (IsKeyDown(KEY_DOWN))
    {
        if (IsKeyDown(KEY_RIGHT))
            player->direction = (Vector2){1, 1};
        else if (IsKeyDown(KEY_LEFT))
            player->direction = (Vector2){-1, 1};
        else
        {
            player->direction = (Vector2){0, 1};
        }
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        if (IsKeyDown(KEY_UP))
            player->direction = (Vector2){1, -1};
        else if (IsKeyDown(KEY_DOWN))
            player->direction = (Vector2){1, 1};
        else
        {
            player->direction = (Vector2){1, 0};
        }
    }
    if (IsKeyDown(KEY_LEFT))
    {
        if (IsKeyDown(KEY_UP))
            player->direction = (Vector2){-1, -1};
        else if (IsKeyDown(KEY_DOWN))
            player->direction = (Vector2){-1, 1};
        else
        {
            player->direction = (Vector2){-1, 0};
        }
    }
}