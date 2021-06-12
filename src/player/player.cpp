#include <huw.hpp>

huw::player::player(huw::sprite *hase, huw::sprite *wolf, huw::game *game)
{
	m_game=game;
	m_hase=hase;
	m_wolf=wolf;

	m_active_char=m_hase;

	//Positionen setzen
	m_hase->pos.x=0;
	m_hase->pos.y=0;
	m_wolf->pos.x=250;
	m_wolf->pos.y=0;
}

void huw::player::update()
{
	//steuerung vom spieler
	//rechts
	static float acceleration_time_right=0;
	if(m_game->keyboard_state[SDL_SCANCODE_D])
	{
		acceleration_time_right+=m_game->delta_t;
		if(acceleration_time_right<ACCELERATION_DURATION_HORIZONTAL)
		{
			if(m_active_char==m_hase)
			{
				m_hase->acc.x+=HASE_ACCELERATION_HORIZONTAL*m_game->delta_t;
			}
			if(m_active_char==m_wolf)
			{
				m_wolf->acc.x+=WOLF_ACCELERATION_HORIZONTAL*m_game->delta_t;
			}
		}
	}
	else
	{
		acceleration_time_right=0;
		if(m_active_char==m_hase && m_hase->acc.x>0)
		{
			m_hase->acc.x-=HASE_DECELERATION_HORIZONTAL*m_game->delta_t;
			if(m_hase->acc.x<0)
			{
				m_hase->acc.x=0;
			}
		}
		if(m_active_char==m_wolf && m_wolf->acc.x>0)
		{
			m_wolf->acc.x-=WOLF_DECELERATION_HORIZONTAL*m_game->delta_t;
			if(m_wolf->acc.x<0)
			{
				m_wolf->acc.x=0;
			}
		}	
	}

	//links
	static float acceleration_time_left=0;
	if(m_game->keyboard_state[SDL_SCANCODE_A])
	{
		acceleration_time_left+=m_game->delta_t;
		if(acceleration_time_left<ACCELERATION_DURATION_HORIZONTAL)
		{
			if(m_active_char==m_hase)
			{
				m_hase->acc.x-=HASE_ACCELERATION_HORIZONTAL*m_game->delta_t;
			}
			if(m_active_char==m_wolf)
			{
				m_wolf->acc.x-=WOLF_ACCELERATION_HORIZONTAL*m_game->delta_t;
			}
		}
	}
	//decelleration
	else
	{
		acceleration_time_left=0;
		if(m_active_char==m_hase && m_hase->acc.x<0)
		{
			m_hase->acc.x+=HASE_DECELERATION_HORIZONTAL*m_game->delta_t;
			if(m_hase->acc.x>0)
			{
				m_hase->acc.x=0;
			}
		}
		if(m_active_char==m_wolf && m_wolf->acc.x<0)
		{
			m_wolf->acc.x+=WOLF_DECELERATION_HORIZONTAL*m_game->delta_t;
			if(m_wolf->acc.x>0)
			{
				m_wolf->acc.x=0;
			}
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
	
	//physik update
	m_hase->physics_update();
	m_wolf->physics_update();

	//render beide Player Charaktere
	m_hase->render();
	m_wolf->render();
}