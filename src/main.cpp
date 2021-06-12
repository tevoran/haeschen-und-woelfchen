#include <huw.hpp>

#undef main

int main(int argc, char *argv[])
{
	huw::game game;

	huw::sprite hase1("../assets/Haeschen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::sprite wolf("../assets/Woelfchen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::sprite abfall("../assets/Muelltonne.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	abfall.pos.x=400;
	abfall.pos.y=RESY-abfall.dst_rect.h;
	huw::player player(&hase1, &wolf, &game);

	bool quit=false;
	while(!quit)
	{
		abfall.render();

		player.update();
		game.update(quit);
	}
}