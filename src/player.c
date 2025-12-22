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
    float delta = GetFrameTime();
    if (IsKeyDown(KEY_W))
    {
        Vector2 newPos = player->position;
        newPos.y -= player->speed * delta * 60;

        int mapX = (int)(newPos.x / 30);
        int mapY = (int)((newPos.y) / 30);

        if (!IsWall(mapX, mapY))
        {
            player->position = newPos;
        }
    }

    if (IsKeyDown(KEY_S))
    {
        Vector2 newPos = player->position;
        newPos.y += player->speed * delta * 60;

        int mapX = (int)(newPos.x / 30);
        int mapY = (int)((newPos.y) / 30);

        if (!IsWall(mapX, mapY))
        {
            player->position = newPos;
        }
    }

    if (IsKeyDown(KEY_A))
    {
        Vector2 newPos = player->position;
        newPos.x -= player->speed * delta * 60;

        int mapX = (int)(newPos.x / 30);
        int mapY = (int)((newPos.y) / 30);

        if (!IsWall(mapX, mapY))
        {
            player->position = newPos;
        }
    }

    if (IsKeyDown(KEY_D))
    {
        Vector2 newPos = player->position;
        newPos.x += player->speed * delta * 60;

        int mapX = (int)(newPos.x / 30);
        int mapY = (int)((newPos.y) / 30);

        if (!IsWall(mapX, mapY))
        {
            player->position = newPos;
        }
    }
    float actualRotSpeed = player->rotSpeed * delta * 60.0f;
    
    if (IsKeyDown(KEY_LEFT)) {
        UpdateDirection(player, actualRotSpeed); 
    }
    if (IsKeyDown(KEY_RIGHT)) {
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