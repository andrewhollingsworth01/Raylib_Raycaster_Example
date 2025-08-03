#include "RenderTwoD.h"
using namespace RenderThreeD;

namespace RenderTwoD
{
    void Render2DMap(const uint8_t map[10][10], Color WallColors[], int TILE_SIZE) {
        for (uint8_t row = 0; row < 10; row++) {
            for (uint8_t col = 0; col < 10; col++) {
                Color color = BLACK;
                if (map[row][col] > 0) {
                    int colorIndex = map[row][col];
                    color = WallColors[colorIndex - 1];
                }

                DrawRectangle(col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
            }
        }
    }

    void Render2DPlayer(const Vector2 position, int TILE_SIZE) {
        DrawCircle(position.x * TILE_SIZE + TILE_SIZE / 2, position.y * TILE_SIZE + TILE_SIZE / 2, 6, ORANGE);
    }

    Vector2 Update2DPlayer(Vector2* position, float* rotation, float sensitivity, const uint8_t map[10][10]) {
        Vector2 forward = Vector2(sin(*rotation * (PI / 180)), cos(*rotation * (PI / 180)));

        Vector2 velocity = Vector2(0, 0);

        // Get how much the mouse moved horizontally
        Vector2 mouseDelta = GetMouseDelta();

        *rotation += mouseDelta.x * sensitivity;

        if (IsKeyDown(KEY_W)) {
            velocity = Vector2(0.01f * forward.x, 0.01f * forward.y);
        }

        if (IsKeyDown(KEY_S)) {
            velocity = Vector2(-0.01f * forward.x, -0.01f * forward.y);
        }

        if (!IsHit(map, Vector2(position->x + velocity.x, position->y + velocity.y), 0.5)) {
            position->x += velocity.x;
            position->y += velocity.y;
        }
        else {

        }

        return forward;
    }

}