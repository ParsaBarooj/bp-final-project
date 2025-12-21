#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct {
    Vector2 position;  
    Vector2 direction; 
    float radius;      
    Color color;   
    float speed;
} Player;


void InitPlayer(Player *player);
void DrawPlayer(Player *player);
void UpdatePlayer(Player *player);
void UpdateDirection(Player *player);

#endif