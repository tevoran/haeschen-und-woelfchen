#include <huw.hpp>
#include <level/actual_levels.hpp>

#undef main

SDL_Color TEXT_COLOR={228,20,228,0};

int main(int argc, char *argv[])
{
	SDL_Color text_color={45, 44, 44, 0};

	huw::game game;
	huw::sprite background("../assets/DarkGhetto.png", & game, 0, 0, 640, 360, RESX, RESY);
	huw::sprite hase("../assets/Haeschen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::sprite wolf("../assets/Woelfchen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::player player(&hase, &wolf, &game);
	huw::level level(huw::level1, &game);

	int current_level=1;

	bool quit=false;
	while(!quit)
	{
		background.render();
		level.render();
		player.update(); //muss vor der level kollision sein
		level.collision(player);

		huw::level_scripts(current_level, game);

		game.update(quit);
	}
}