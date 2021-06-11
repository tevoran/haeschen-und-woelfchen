#include <huw.hpp>

int main()
{
	huw::game game;

	huw::sprite sprite("../assets/test_sprite.png", &game, 0, 0, 32, 32);

	for(int i=0; i<100; i++)
	{
		sprite.render(100, 100);
		game.update();
	}
	SDL_Delay(1000);
} 