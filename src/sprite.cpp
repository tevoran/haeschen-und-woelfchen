#include <huw.hpp>

huw::sprite::sprite(const char* file_path, huw::game *game, int x, int y, int w, int h, int target_w, int target_h) //Angaben in Pixeln

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

	dst_rect.w=target_w;
	dst_rect.h=target_h;

	m_texture=SDL_CreateTextureFromSurface(m_game->m_renderer, tmp_surface);
	if(m_texture==NULL)
	{
		std::cout << "Texture is broken" << std::endl;
	}
	SDL_FreeSurface(tmp_surface);

	pos.x=0;
	pos.y=0;
	acc.x=0;
	acc.y=0;
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
	dst_rect.x=pos.x;
	dst_rect.y=pos.y;

	if(SDL_RenderCopy(m_game->m_renderer, m_texture, &m_src_rect, &dst_rect)!=0)
	{
		std::cout << "can't draw" << std::endl;
		std::cout << "ERROR: " << SDL_GetError() << std::endl;
	}
}

void huw::sprite::physics_update()
{
	//schwerkraft
	acc.y+=GRAVITY*m_game->delta_t;

	//position aktualisieren
	pos.x=pos.x+acc.x*m_game->delta_t;
	pos.y=pos.y+acc.y*m_game->delta_t;

	if(pos.x<0)
	{
		pos.x=0;
		acc.x=0;
	}

	//boden
	if((pos.y+dst_rect.h)>RESY)
	{
		pos.y=RESY-dst_rect.h;
		acc.y=0;
	}
}
