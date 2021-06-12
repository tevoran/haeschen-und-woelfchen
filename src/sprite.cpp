#include <huw.hpp>

huw::sprite::sprite(const char* file_path, huw::game *game, int x, int y, int w, int h) //Angaben in Pixeln

{
	std::cout << "loading sprite from " << file_path << std::endl;

	m_game=game;
	SDL_Surface *tmp_surface = IMG_Load(file_path);
	if(tmp_surface==NULL)
	{
		std::cout << "Sprite couldn't be loaded" << std::endl;
		std::cout << "ERROR: " << SDL_GetError() << std::endl;
	}
	m_src_rect.x=x;
	m_src_rect.y=y;
	m_src_rect.w=w;
	m_src_rect.h=h;

	m_texture=SDL_CreateTextureFromSurface(m_game->m_renderer, tmp_surface);
	if(m_texture==NULL)
	{
		std::cout << "Texture is broken" << std::endl;
	}
	SDL_FreeSurface(tmp_surface);
}

void huw::sprite::render(int x, int y, int w, int h)
{
	dst_rect.x=x;
	dst_rect.y=y;
	dst_rect.w=w;
	dst_rect.h=h;
	if(SDL_RenderCopy(m_game->m_renderer, m_texture, &m_src_rect, &dst_rect)!=0)
	{
		std::cout << "can't draw" << std::endl;
		std::cout << "ERROR: " << SDL_GetError() << std::endl;
	}
}

void huw::sprite::render()
{
	if(SDL_RenderCopy(m_game->m_renderer, m_texture, &m_src_rect, &dst_rect)!=0)
	{
		std::cout << "can't draw" << std::endl;
		std::cout << "ERROR: " << SDL_GetError() << std::endl;
	}
}