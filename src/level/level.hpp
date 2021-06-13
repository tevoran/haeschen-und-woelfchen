#pragma once
#include <huw.hpp>

#define ABFALL 1
#define NEON_L 2
#define NEON_M 3
#define NEON_R 4
#define TAUBE 5
#define GHETTO 6
#define WOLF 7
#define HASE 8


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
		std::vector<huw::sprite> ghetto;

		//gegner
		std::vector<huw::sprite> taube;
		std::vector<bool> taube_richtung;


	public:

		level(uint8_t level[11][20], huw::game *game, huw::player& player);
		void render();
		void enemy_update();
		void collision(huw::player& player);
		bool check_coll(huw::player& player, std::vector<huw::sprite> &objects);

	};

	void level_scripts(int current_level, huw::game& game);
}