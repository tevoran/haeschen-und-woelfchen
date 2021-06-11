#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace huw
{

	class game
	{
	private:
		SDL_Window *m_window=NULL;
		SDL_Renderer *m_renderer=NULL;
	public:
		game();
		~game();
		void update();
	};

}