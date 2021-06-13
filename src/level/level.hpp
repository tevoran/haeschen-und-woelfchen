#pragma once
#include <huw.hpp>

#define ABFALL 1
#define NEON_L 2
#define NEON_M 3
#define NEON_R 4
#define NEON 5
#define TAUBE 6
#define GHETTO 7
#define WOLF 8
#define HASE 9


#define LEVEL_X 20
#define LEVEL_Y 11

namespace huw
{

	class level
	{
	private:
		huw::game *m_game=NULL;
		bool activated=false;

	public:
		std::vector<huw::sprite> abfall;
		std::vector<bool> abfall_active;
		std::vector<huw::sprite> neon_l;
		std::vector<huw::sprite> neon_m;
		std::vector<huw::sprite> neon_r;
		std::vector<huw::sprite> neon;
		std::vector<huw::sprite> ghetto;

		//gegner
		std::vector<huw::sprite> taube;
		std::vector<huw::sprite> taube_tot;
		std::vector<bool> taube_richtung;
		std::vector<bool> taube_alive;


	public:
		level(uint8_t level[11][20], huw::game *game, huw::player& player);
		void render();
		void enemy_update();
		void collision(huw::player& player);
		bool check_coll(huw::player& player, std::vector<huw::sprite> &objects);
		bool done(huw::player& player);
	};

	void level_scripts(int current_level, huw::game& game);
}