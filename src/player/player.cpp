#include <huw.hpp>

huw::player::player(huw::sprite *hase, huw::sprite *wolf, huw::game *game)
{
	m_game=game;
	m_hase=hase;
	m_wolf=wolf;

	m_active_char=m_hase;

	//Positionen setzen
	m_hase->dst_rect.x=0;
	m_hase->dst_rect.y=0;
	m_wolf->dst_rect.x=250;
	m_wolf->dst_rect.y=0;

	m_wolf->dst_rect.w=PLAYER_SIZE;
	m_wolf->dst_rect.h=PLAYER_SIZE;
	m_hase->dst_rect.w=PLAYER_SIZE;
	m_hase->dst_rect.h=PLAYER_SIZE;

}

void huw::player::update()
{
	//steuerung vom spieler
	if(m_game->keyboard_state[SDL_SCANCODE_D])
	{
		if(m_active_char==m_hase)
		{
			m_hase->dst_rect.x+=1;
		}
		if(m_active_char==m_wolf)
		{
			m_wolf->dst_rect.x+=1;
		}
	}

	if(m_game->keyboard_state[SDL_SCANCODE_A])
	{
		if(m_active_char==m_hase)
		{
			m_hase->dst_rect.x-=1;
		}
		if(m_active_char==m_wolf)
		{
			m_wolf->dst_rect.x-=1;
		}
	}

	//charakter wechseln
	static bool key_lshift_down=false;
	if(m_game->keyboard_state[SDL_SCANCODE_LSHIFT])
	{
		bool already_changed=false;
		if(m_active_char==m_hase && already_changed==false && key_lshift_down==false)
		{
			m_active_char=m_wolf;
			already_changed=true;
		}
		if(m_active_char==m_wolf && already_changed==false && key_lshift_down==false)
		{
			m_active_char=m_hase;
			already_changed=true;
		}
		key_lshift_down=true;
	}
	if(!m_game->keyboard_state[SDL_SCANCODE_LSHIFT])
	{
		key_lshift_down=false;
	}
	
	//render beide Player Charaktere
	m_hase->render();
	m_wolf->render();
}