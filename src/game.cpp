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

	SDL_SetRenderDrawColor(m_renderer, 0,0,0,0); //schwarzer Hintergrund

	std::cout << "initializing SDL2_image" << std::endl;
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

	//Tastaturzustandsarray
	keyboard_state=SDL_GetKeyboardState(NULL);
	if(keyboard_state==NULL)
	{
		std::cout << "Keyboard not available" << std::endl;
	}
}

huw::game::~game()
{
	std::cout << "ending SDL2" << std::endl;
	SDL_Quit();
}

void huw::game::update()
{
	SDL_PumpEvents(); //updaten der Eventqueue
	SDL_RenderPresent(m_renderer);
	SDL_RenderClear(m_renderer);
}
