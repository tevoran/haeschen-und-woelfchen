#pragma once
#include <huw.hpp>

#define ABFALL 1
#define NEON 2


#define LEVEL_X 20
#define LEVEL_Y 11

namespace huw
{

	class level
	{
	private:
	public:
		std::vector<huw::sprite> abfall;
		std::vector<huw::sprite> neon;		

	public:
		level(uint8_t level[11][20], huw::game& game);
		void render();
	};
}