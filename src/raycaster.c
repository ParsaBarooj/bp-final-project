#include "raycaster.h"
#include <math.h>

void Render3DView(Player *player)
{

    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2, (Color){30, 30, 60, 255});

    DrawRectangle(0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2, (Color){60, 40, 20, 255});
}