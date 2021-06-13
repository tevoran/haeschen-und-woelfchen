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
	int current_instance=0;


	bool quit=false;
	while(!quit)
	{
		background.render();
		level[current_instance].enemy_update();
		level[current_instance].render();
		if(level[current_instance].done(player))
		{
			current_level++;
			current_instance++;
			if(current_level==1)
			{
				level.push_back(huw::level(huw::level1, &game, player)); //level 1
			}
		}
		if(level[current_instance].game_over(player))
		{
			current_instance++;
			std::cout << current_instance << std::endl;
			if(current_level==0)
			{
				level.push_back(huw::level(huw::level0, &game, player)); //level 0
			}
			if(current_level==1)
			{
				level.push_back(huw::level(huw::level1, &game, player)); //level 1
			}
		}
		player.update(); //muss vor der level kollision sein
		level[current_instance].collision(player);

		huw::level_scripts(current_level, game);

		game.update(quit);
	}
}