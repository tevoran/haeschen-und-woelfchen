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
		huw::game *m_game=NULL;

	public:
		std::vector<huw::sprite> abfall;
		std::vector<huw::sprite> neon_l;
		std::vector<huw::sprite> neon_m;
		std::vector<huw::sprite> neon_r;		

	public:

		level(uint8_t level[11][20], huw::game *game);
		void render();
		void collision(huw::player& player);
		void check_coll(huw::player& player, std::vector<huw::sprite> &objects);

	};

	void level_scripts(int current_level, huw::game& game);
}