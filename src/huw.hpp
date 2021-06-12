#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define PLAYER_SIZE 64

namespace huw
{
	class game
	{
	private:
		SDL_Window *m_window=NULL;
		SDL_Event m_event;
	public:
		SDL_Renderer *m_renderer=NULL;
		const uint8_t *keyboard_state=NULL;
	public:
		game();
		~game();
		void update(bool& quit);
	};

	class sprite
	{
	private:
		SDL_Texture *m_texture=NULL;
		huw::game *m_game=NULL;
		SDL_Rect m_src_rect;
	public:
		SDL_Rect dst_rect; //Zielposition und Größe

	public:
		sprite(const char* file_path, huw::game *game, int x, int y, int w, int h); //Angaben in Pixeln
		void render(int x, int y, int w, int h);
		void render();
	};

	class player
	{
	private:
		huw::game *m_game=NULL;
		huw::sprite *m_hase=NULL;
		huw::sprite *m_wolf=NULL;
		huw::sprite *m_active_char=NULL;
	public:
		player(huw::sprite *hase, huw::sprite *wolf, huw::game *game);
		void update(); //Player zeichnen, Steuerung und so weiter

	};

}