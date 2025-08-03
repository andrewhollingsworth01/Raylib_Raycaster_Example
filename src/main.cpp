// Raycaster_Test_5.31.2025.cpp : Defines the entry point for the application.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include <raylib.h>
#include "RenderThreeD.h"
#include "RenderTwoD.h"

using namespace RenderTwoD;
using namespace RenderThreeD;

const uint8_t map[10][10] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 2, 0, 3, 3, 0, 0, 0, 1 },
    { 1, 2, 2, 0, 3, 0, 0, 0, 0, 1 },
    { 1, 0, 2, 0, 3, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

#define TILE_SIZE           40
#define DEFAULT_RAY_LENGTH 250

//#ifndef PI
//#define PI 3.14159265358979323846
//#endif

Color WallColors[] = { RED, GREEN, BLUE };



int main(void) {
    int lineWidth = 10;
    int windowWidth = (10 * TILE_SIZE) + (lineWidth * 60);
    InitWindow(windowWidth, 10 * TILE_SIZE, "raycasting");

    DisableCursor();  // Lock and hide cursor *after* InitWindow

    Vector2 playerPosition = Vector2(1, 1);
    Vector2 playerForward = {};
    float playerRotation = 0.0f;
    float mouseSensititvity = 0.1f;

    double lastTime = GetTime();
    while (!WindowShouldClose()) {
        double currentTime = GetTime();

        if (currentTime - lastTime > 1.0f / 150.0f) {
            lastTime = currentTime;
            playerForward = Update2DPlayer(&playerPosition, &playerRotation, mouseSensititvity, map);
        }

        BeginDrawing();

        ClearBackground(BLACK);

        Render2DMap(map, WallColors, TILE_SIZE);
        Render2DPlayer(playerPosition, TILE_SIZE);
        Render3DMap(playerPosition, playerRotation, lineWidth, 60, TILE_SIZE, map);

        DrawFPS(2, 0);
        DrawText(TextFormat("Player X: %2.1f, Y: %2.1f", playerForward.x, playerForward.y), 2, 20, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
