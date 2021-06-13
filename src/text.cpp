#include <huw.hpp>

huw::text::text(huw::game *game, const char *text, SDL_Color& text_color, bool isBig)
{
	SDL_Surface *tmp_surface=NULL;
	if(isBig){
		tmp_surface=TTF_RenderText_Solid(game->font_big, text, text_color);
	}
	else{
		tmp_surface=TTF_RenderText_Solid(game->font_small, text, text_color);
	}
	text_texture=SDL_CreateTextureFromSurface(game->m_renderer, tmp_surface);
	m_game=game;
	m_h=tmp_surface->h;
	m_w=tmp_surface->w;
	SDL_FreeSurface(tmp_surface);
}

void huw::text::render(int x, int y)
{
	SDL_Rect rect;
	rect.w=m_w;
	rect.h=m_h;
	rect.x=x;
	rect.y=y;
	SDL_RenderCopy(m_game->m_renderer, text_texture, NULL, &rect);
}