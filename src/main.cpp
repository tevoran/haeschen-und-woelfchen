#include <huw.hpp>

#undef main

int main(int argc, char *argv[])
{
	huw::game game;

	huw::sprite hase1("../assets/Haeschen1.png", &game, 0, 0, 32, 32);
	huw::sprite hase2("../assets/Haeschen1.png", &game, 0, 0, 32, 32);
	huw::player player(&hase1, &hase2, &game);

	bool quit=false;
	while(!quit)
	{
		player.update();
		game.update(quit);
	}
	SDL_Delay(1000);
}