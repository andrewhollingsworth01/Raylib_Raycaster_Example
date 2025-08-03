#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include <raylib.h>
#include "RenderThreeD.h"

namespace RenderTwoD
{
	void Render2DMap(const uint8_t map[10][10], Color WallColors[], int TILE_SIZE);

	void Render2DPlayer(const Vector2 position, int TILE_SIZE);

	Vector2 Update2DPlayer(Vector2* position, float* rotation, float sensitivity, const uint8_t map[10][10]);
};