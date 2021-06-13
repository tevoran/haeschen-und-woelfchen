#include <huw.hpp>
#include <level/actual_levels.hpp>

#undef main



int main(int argc, char *argv[])
{
	huw::game game;
	huw::sprite background("../assets/DarkGhetto.png", & game, 0, 0, 640, 360, RESX, RESY);
	huw::sprite hase("../assets/Haeschen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::sprite wolf("../assets/Woelfchen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::player player(&hase, &wolf, &game);
	huw::level level(huw::level1, &game);

	bool quit=false;
	while(!quit)
	{
		background.render();
		level.render();
		player.update();
		level.collision(player);
		game.update(quit);
	}
}