#include <huw.hpp>

huw::game::game()
{
	std::cout << "initializing SDL2" << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);
}

huw::game::~game()
{
	std::cout << "ending SDL2" << std::endl;
	SDL_Quit();
}