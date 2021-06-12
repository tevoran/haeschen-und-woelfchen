#include <huw.hpp>

#undef main

int main(int argc, char *argv[])
{
	huw::game game;

	huw::sprite hase1("../assets/Haeschen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::sprite wolf("../assets/Woelfchen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::player player(&hase1, &wolf, &game);

	bool quit=false;
	while(!quit)
	{
		player.update();
		game.update(quit);
	}
}