#include <huw.hpp>
#include <level/actual_levels.hpp>

#undef main


int main(int argc, char *argv[])
{
	SDL_Color TEXT_COLOR={228,20,228,0};


	huw::game game;
	huw::sprite background("../assets/DarkGhetto.png", & game, 0, 0, 640, 360, RESX, RESY);
	huw::sprite hase("../assets/Haeschen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::sprite wolf("../assets/Woelfchen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::player player(&hase, &wolf, &game);

	std::vector<huw::level> level;
	level.push_back(huw::level(huw::levelTest, &game, player)); //level 0


	int current_level=0;

	bool quit=false;
	while(!quit)
	{
		background.render();
		level[current_level].enemy_update();
		level[current_level].render();
		if(level[current_level].done(player))
		{
			current_level++;
			if(current_level==1)
			{
				level.push_back(huw::level(huw::level1, &game, player)); //level 1
			}
		}
		player.update(); //muss vor der level kollision sein
		level[current_level].collision(player);

		huw::level_scripts(current_level, game);

		game.update(quit);
	}
}