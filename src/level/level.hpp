#pragma once
#include <huw.hpp>

#define ABFALL 1

#define LEVEL_X 20
#define LEVEL_Y 11

namespace huw
{

	class level
	{
	private:
		huw::game *m_game=NULL;

	public:
		std::vector<huw::sprite> abfall;

	public:
		level(uint8_t level[21][11], huw::game *game);
		void render();
		void collision(huw::player& player);

	};
}