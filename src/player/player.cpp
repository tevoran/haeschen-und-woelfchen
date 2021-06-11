#include <huw.hpp>

huw::player::player(huw::sprite *hase, huw::sprite *wolf, huw::game *game)
{
	m_game=game;
	m_hase=hase;
	m_wolf=wolf;

	m_active_char=m_wolf;

	//Positionen setzen
	m_hase_pos.x=0;
	m_hase_pos.y=0;
	m_wolf_pos.x=250;
	m_wolf_pos.y=0;

}

void huw::player::update()
{
	//steuerung vom spieler
	if(m_game->keyboard_state[SDL_SCANCODE_D])
	{
		std::cout << m_wolf_pos.x << std::endl;
		if(m_active_char==m_hase)
		{
			m_hase_pos.x+=1;
		}
		if(m_active_char==m_wolf)
		{
			m_wolf_pos.x+=1;
		}
	}

	if(m_game->keyboard_state[SDL_SCANCODE_A])
	{
		std::cout << m_wolf_pos.x << std::endl;
		if(m_active_char==m_hase)
		{
			m_hase_pos.x-=1;
		}
		if(m_active_char==m_wolf)
		{
			m_wolf_pos.x-=1;
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
	m_hase->render(m_hase_pos.x, m_hase_pos.y, PLAYER_SIZE, PLAYER_SIZE);
	m_wolf->render(m_wolf_pos.x, m_wolf_pos.y, PLAYER_SIZE, PLAYER_SIZE);
}