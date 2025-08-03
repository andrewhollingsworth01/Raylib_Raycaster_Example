#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include <raylib.h>

namespace RenderThreeD
{
	bool IsHit(const uint8_t map[10][10], Vector2 point, float size);

	void StepRay(const Vector2 position, Vector2 forward, const int stepCount, const int stepLength, int* incr, Color color, Vector2* pHit, int TILE_SIZE, const uint8_t map[10][10]);

	float Dist(const Vector2 v1, const Vector2 v2);

	void Render3DMap(Vector2 cameraPosition, float cameraRotation, int lineThickness, int fov, int TILE_SIZE, const uint8_t map[10][10]);
}