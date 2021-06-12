#pragma once
#include <huw.hpp>

#define ABFALL 1
#define NEON_L 2
#define NEON_M 3
#define NEON_R 4

#define LEVEL_X 20
#define LEVEL_Y 11

namespace huw
{

	class level
	{
	private:
	public:
		std::vector<huw::sprite> abfall;
		std::vector<huw::sprite> neon_l;
		std::vector<huw::sprite> neon_m;
		std::vector<huw::sprite> neon_r;		

	public:
		level(uint8_t level[11][20], huw::game& game);
		void render();
	};
}