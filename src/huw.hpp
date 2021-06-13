#pragma once

#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <definitions.hpp>

using namespace std::chrono;

namespace huw

{
	struct vec2
	{
		float x;
		float y;
	};

	class game
	{
	private:
		SDL_Window *m_window=NULL;
		SDL_Event m_event;

		//frame time timer
		steady_clock::time_point m_old_frame;
		steady_clock::time_point m_new_frame;
	public:
		SDL_Renderer *m_renderer=NULL;
		const uint8_t *keyboard_state=NULL;
		TTF_Font *font=NULL;

		//frametime
		float delta_t; //in sekunden

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
		huw::vec2 pos; //aktuelle position
		huw::vec2 acc; //aktuelle beschleunigung
		SDL_Rect dst_rect; //Zielposition und Größe

	public:
		sprite(const char* file_path, huw::game *game, int x, int y, int w, int h, int target_w, int target_h); //Angaben in Pixeln
		void render(int x, int y, int w, int h);
		void render();
		void physics_update();
	};

	class player
	{
	private:
		huw::game *m_game=NULL;
		huw::sprite *m_active_char=NULL;
	public:
		huw::sprite *m_hase=NULL;
		huw::sprite *m_wolf=NULL;

		bool m_wolf_x_plus=false;
		bool m_wolf_x_minus=false;
		bool m_wolf_y_plus=false;
		bool m_wolf_y_minus=false;

		bool m_hase_x_plus=false;
		bool m_hase_x_minus=false;
		bool m_hase_y_plus=false;
		bool m_hase_y_minus=false;

		player(huw::sprite *hase, huw::sprite *wolf, huw::game *game);
		void update(); //Player zeichnen, Steuerung und so weiter

	};

	bool collision(huw::sprite& a, huw::sprite& b);

}

#include <level/level.hpp>