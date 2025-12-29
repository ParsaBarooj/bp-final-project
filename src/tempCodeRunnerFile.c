if (IsKeyDown(KEY_W))
    {
        Vector2 newPos = player->position;
        newPos.x += player->direction.x * moveSpeed;
        newPos.y += player->direction.y * moveSpeed;

        int mapX = (int)(newPos.x / 30);
        int mapY = (int)(newPos.y / 30);

        if (!IsWall(mapX, mapY))
        {
            player->position = newPos;
        }
    }