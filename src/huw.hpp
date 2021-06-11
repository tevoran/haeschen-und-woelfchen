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
	public:
		SDL_Renderer *m_renderer=NULL;

	public:
		game();
		~game();
		void update();
	};

	class sprite
	{
	private:
		SDL_Texture *m_texture=NULL;
		huw::game *m_game=NULL;
		SDL_Rect m_src_rect;
		SDL_Rect m_dst_rect;
	public:
		sprite(const char* file_path, huw::game *game, int x, int y, int w, int h); //Angaben in Pixeln
		void render(int x, int y);
	};

}