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
	//decelleration
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
	//stoppen des nicht aktiven charakters
	if(m_active_char==m_hase && m_wolf->acc.x>0)
	{
		m_wolf->acc.x-=WOLF_DECELERATION_HORIZONTAL*m_game->delta_t;
		if(m_wolf->acc.x<0)
		{
			m_wolf->acc.x=0;
		}
	}
	if(m_active_char==m_wolf && m_hase->acc.x>0)
	{
		m_hase->acc.x-=WOLF_DECELERATION_HORIZONTAL*m_game->delta_t;
		if(m_hase->acc.x<0)
		{
			m_hase->acc.x=0;
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
	//stoppen des nicht aktiven charakters
	if(m_active_char==m_hase && m_wolf->acc.x<0)
	{
		m_wolf->acc.x+=WOLF_DECELERATION_HORIZONTAL*m_game->delta_t;
		if(m_wolf->acc.x>0)
		{
			m_wolf->acc.x=0;
		}
	}
	if(m_active_char==m_wolf && m_hase->acc.x<0)
	{
		m_hase->acc.x+=WOLF_DECELERATION_HORIZONTAL*m_game->delta_t;
		if(m_hase->acc.x>0)
		{
			m_hase->acc.x=0;
		}
	}

	//jump
	static float acceleration_time_jump=0;
	if(m_game->keyboard_state[SDL_SCANCODE_W])
	{
		bool hase_standing = (m_hase->pos.y == RESY - m_hase->dst_rect.h);
		bool wolf_standing = (m_wolf->pos.y == RESY - m_wolf->dst_rect.h);
		acceleration_time_jump+=m_game->delta_t;
		if(acceleration_time_jump<ACCELERATION_DURATION_VERTICAL)
		{
			if(m_active_char==m_hase && hase_standing)
			{
				m_hase->acc.y-=HASE_ACCELERATION_VERTICAL;
			}
			if(m_active_char==m_wolf && wolf_standing)
			{
				m_wolf->acc.y-=WOLF_ACCELERATION_VERTICAL;
			}
		}
	}
	//decelleration
	else
	{
		acceleration_time_jump=0;
		if(m_active_char==m_hase && m_hase->acc.y<0)
		{
			m_hase->acc.y+=HASE_DECELERATION_VERTICAL*m_game->delta_t;
			if(m_hase->acc.y>0)
			{
				m_hase->acc.y=0;
			}
		}
		if(m_active_char==m_wolf && m_wolf->acc.y<0)
		{
			m_wolf->acc.y+=WOLF_DECELERATION_VERTICAL*m_game->delta_t;
			if(m_wolf->acc.y>0)
			{
				m_wolf->acc.y=0;
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

	//kollisionen zurücksetzen
	m_wolf_x_plus=false;
	m_wolf_x_minus=false;
	m_wolf_y_plus=false;
	m_wolf_y_minus=false;

	m_hase_x_plus=false;
	m_hase_x_minus=false;
	m_hase_y_plus=false;
	m_hase_y_minus=false;
}