#include "RenderThreeD.h"

namespace RenderThreeD
{
    bool IsHit(const uint8_t map[10][10], Vector2 point, float size) {
        for (uint8_t row = 0; row < 10; row++) {
            for (uint8_t col = 0; col < 10; col++) {
                if (col < point.x + size &&
                    col + size > point.x &&
                    row < point.y + size &&
                    row + size > point.y && map[row][col] > 0) {
                    return true;
                }
            }
        }

        return false;
    }

    void StepRay(const Vector2 position, Vector2 forward, const int stepCount, const int stepLength, int* incr, Color color, Vector2* pHit, int TILE_SIZE, const uint8_t map[10][10]) {
        Vector2 start = Vector2(position.x, position.y);

        Vector2 end = Vector2((position.x + (forward.x / stepLength)), (position.y + (forward.y / stepLength)));

        pHit->x = end.x;
        pHit->y = end.y;

        DrawLine(start.x * TILE_SIZE + TILE_SIZE / 2, start.y * TILE_SIZE + TILE_SIZE / 2, end.x * TILE_SIZE + TILE_SIZE / 2, end.y * TILE_SIZE + TILE_SIZE / 2, GRAY);

        if (!IsHit(map, end, 0.5) && *incr < stepCount) {
            *incr += 1;
            StepRay(end, forward, stepCount, stepLength, incr, color, pHit, TILE_SIZE, map);
        }
        else {
            *incr = 0;
        }
    }

    float Dist(const Vector2 v1, const Vector2 v2) {
        return powf(v1.x - v2.x, 2) + powf(v1.y - v2.y, 2);
    }

    void Render3DMap(Vector2 cameraPosition, float cameraRotation, int lineThickness, int fov, int TILE_SIZE, const uint8_t map[10][10]) {
        for (int i = -fov / 2; i < fov / 2; i++) {
            int c = 0;
            Vector2 hit;

            Vector2 dir = Vector2(sin((cameraRotation + i) * (PI / 180)), cos((cameraRotation + i) * (PI / 180)));

            StepRay(cameraPosition, dir, 1000, 100, &c, GRAY, &hit, TILE_SIZE, map);

            float dist = Dist(cameraPosition, hit);

            Color color = { 150 - dist * 1.5, 150 - dist * 1.5, 150 - dist * 1.5, 255 };

            DrawRectangle((i * lineThickness + (lineThickness * fov / 2) + (10 * TILE_SIZE)), 5 * TILE_SIZE - (1000 / dist) / 2, lineThickness, (1000 / dist), color);
        }
    }

}