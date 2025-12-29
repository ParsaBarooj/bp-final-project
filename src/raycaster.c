#include "raycaster.h"
#include <math.h>
#include "map.h"
extern int map[20][20];
void Render3DView(Player *player)
{
    ClearBackground(BLACK);
    
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2, (Color){100, 180, 255, 255});
    DrawRectangle(0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2, (Color){64, 64, 64, 255});
    // --- شروع Raycasting Loop ---
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        // ۱. محاسبه موقعیت دوربین (-1 تا +1)
        float cameraX = 2 * x / (float)SCREEN_WIDTH - 1;
        
        // ۲. محاسبه جهت پرتو برای این ستون
        float rayDirX = player->direction.x + player->plane.x * cameraX;
        float rayDirY = player->direction.y + player->plane.y * cameraX;
        
        // ۳. موقعیت فعلی در نقشه
        int mapX = (int)player->position.x / 30;
        int mapY = (int)player->position.y / 30;
        
        // ۴. فاصله تا مرز بعدی در X و Y
        float deltaDistX = (rayDirX == 0) ? 1e30 : fabsf(1 / rayDirX);
        float deltaDistY = (rayDirY == 0) ? 1e30 : fabsf(1 / rayDirY);
        
        // ۵. جهت حرکت در نقشه (-1 یا +1)
        int stepX, stepY;
        float sideDistX, sideDistY;
        
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (player->position.x / 30 - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player->position.x / 30) * deltaDistX;
        }
        
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (player->position.y / 30 - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player->position.y / 30) * deltaDistY;
        }
        
        // ۶. الگوریتم DDA - پیدا کردن دیوار
        int hit = 0;
        int side = 0; // 0 = برخورد X, 1 = برخورد Y
        
        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            
            // چک کردن برخورد با دیوار
            if (mapX < 0 || mapX >= 600 || mapY < 0 || mapY >= 600) {
                hit = 1; // خارج از نقشه
            } else if (map[mapY][mapX] > 0) {
                hit = 1; // برخورد با دیوار
            }
        }
        
        // ۷. محاسبه فاصله (با تصحیح چشم ماهی)
        float perpWallDist;
        if (side == 0) {
            perpWallDist = (sideDistX - deltaDistX);
        } else {
            perpWallDist = (sideDistY - deltaDistY);
        }
        
        // ۸. محاسبه ارتفاع خط
        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
        
        // ۹. محاسبه نقاط شروع و پایان رسم
        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;
        
        // ۱۰. انتخاب رنگ بر اساس جهت دیوار
        Color color;
        if (map[mapY][mapX] == 1) {
            if (side == 1) {
                color = (Color){180, 180, 180, 255}; // دیوار افقی (تیره‌تر)
            } else {
                color = (Color){220, 220, 220, 255}; // دیوار عمودی (روشن‌تر)
            }
        } else {
            color = RED; // برای دیوارهای دیگه (اگر داشتیم)
        }
        
        // ۱۱. رسم خط عمودی
        DrawLine(x, drawStart, x, drawEnd, color);
    }
    // --- پایان Raycasting Loop ---
    
}