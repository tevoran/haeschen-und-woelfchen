#pragma once
#include "level.hpp"

namespace huw
{
	uint8_t levelTest[11][20]=
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NEON, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NEON, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NEON_L, NEON_M, NEON_M, NEON_M, NEON_R},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NEON, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NEON, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, HASE, WOLF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, GHETTO, 0, 0, 0, 0, 0, 0}
	};
	
	uint8_t level0[11][20]=
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, NEON_L, NEON_M, NEON_M, NEON_R, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, GHETTO, 0, 0, 0, 0},
		{0, NEON_L, NEON_M, NEON_M, NEON_R, 0, 0, 0, 0, 0, 0, 0, 0, 0, NEON_L, NEON_R, 0, 0, 0, HASE},
		{0, 0, 0, 0, 0, 0, 0, 0, ABFALL, 0, TAUBE, TAUBE, 0, ABFALL, 0, 0, 0, 0, 0, WOLF}
	};

		uint8_t level1[11][20]=
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, WOLF, 0, 0, 0, 0, NEON_L, NEON_R, ABFALL, 0, 0, TAUBE, 0, 0, ABFALL, 0, 0, 0, 0},
		{NEON_L, NEON_M, NEON_M, NEON_R, 0, 0, 0, 0, 0, NEON_L, NEON_M, NEON_M, NEON_M, NEON_M, NEON_M, NEON_R, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, GHETTO, 0, 0, 0, 0, 0},
		{0, 0, NEON_L, NEON_M, NEON_M, NEON_R, 0, 0, 0, 0, 0, 0, 0, 0, NEON, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{HASE, 0, 0, ABFALL, 0, 0, TAUBE, 0, ABFALL, 0, 0, TAUBE, 0, 0, 0, TAUBE, 0, ABFALL, 0, 0}
	};

		uint8_t level2[11][20]=
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, GHETTO, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, WOLF, 0, 0, 0, 0, NEON_L, NEON_R, ABFALL, 0, 0, TAUBE, 0, 0, ABFALL, 0, 0, 0, 0},
		{NEON_L, NEON_M, NEON_M, NEON_R, 0, 0, 0, 0, 0, NEON_L, NEON_M, NEON_M, NEON_M, NEON_M, NEON_M, NEON_R, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, GHETTO, 0, 0, 0, 0, 0},
		{0, 0, NEON_L, NEON_M, NEON_M, NEON_R, 0, 0, 0, 0, 0, 0, 0, 0, NEON, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{HASE, 0, 0, ABFALL, 0, 0, TAUBE, 0, ABFALL, 0, 0, TAUBE, 0, 0, 0, TAUBE, 0, ABFALL, 0, 0}
	};

}