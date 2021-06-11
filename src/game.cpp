#include <huw.hpp>

huw::game::game()
{
	std::cout << "Starting the glorious and lovely game of Häschen und Wölfchen" << std::endl;
	std::cout << "initializing SDL2" << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);

	std::cout << "creating window" << std::endl;
	m_window=SDL_CreateWindow("Häschen und Wölfchen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0 );

	std::cout << "creating renderer" << std::endl;
	m_renderer=SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if(m_renderer==NULL)
	{
		std::cout << "RENDERER is bad anc evil and doesn't work" << std::endl;
	}

	SDL_SetRenderDrawColor(m_renderer, 255,0,255,0); //pinker Hintergrund

	std::cout << "initializing SDL2_image" << std::endl;
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
}

huw::game::~game()
{
	std::cout << "ending SDL2" << std::endl;
	SDL_Quit();
}

void huw::game::update()
{
	SDL_RenderPresent(m_renderer);
	//SDL_RenderClear(m_renderer);
}
