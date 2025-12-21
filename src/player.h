#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct {
    Vector2 position;  
    Vector2 direction;
    Vector2 plane; 
    float radius;      
    Color color;   
    float speed;
    float rotSpeed
} Player;


void InitPlayer(Player *player);
void DrawPlayer(Player *player);
void UpdatePlayer(Player *player);
void UpdateDirection(Player *player, float angle);

#endif