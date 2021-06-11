#include <huw.hpp>

int main()
{
	huw::game game;

	huw::sprite hase1("../assets/Haeschen1.png", &game, 0, 0, 32, 32);
	huw::sprite hase2("../assets/Haeschen1.png", &game, 0, 0, 32, 32);
	huw::player player(&hase1, &hase2, &game);

	while(1)
	{
		player.update();
		game.update();
	}
	SDL_Delay(1000);
} 