#include <huw.hpp>

huw::player::player(huw::sprite *hase, huw::sprite *wolf, huw::game *game)
{
	m_game=game;
	m_hase=hase;
	m_wolf=wolf;

	m_active_char=m_hase;

	//Positionen setzen
	m_hase_pos.x=0;
	m_hase_pos.y=0;
	m_wolf_pos.x=0;
	m_wolf_pos.y=0;

}

void huw::player::update()
{
	//steuerung vom spieler
	if(m_game->keyboard_state[SDL_SCANCODE_D])
	{
		m_hase_pos.x+=1;
	}
	
	//render beide Player Charaktere
	m_hase->render(m_hase_pos.x, m_hase_pos.y, 64, 64);
	m_wolf->render(m_wolf_pos.y, m_wolf_pos.y, 64, 64);
}