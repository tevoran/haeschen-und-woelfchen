#include <huw.hpp>

huw::level::level(uint8_t level[21][11], huw::game *game)
{
	m_game=game;
	for(int iy=0; iy<LEVEL_Y; iy++)
	{
		for(int ix=0; ix<LEVEL_X; ix++)
		{
			switch(level[ix][iy])
			{
				case ABFALL:
					abfall.push_back(huw::sprite("../assets/Muelltonne.png", m_game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					abfall[abfall.size()-1].pos.x=ix*PLAYER_SIZE;
					abfall[abfall.size()-1].pos.y=iy*PLAYER_SIZE;
				break;
			}
		}
	}
}

void huw::level::render()
{
	for(int i=0; i<abfall.size(); i++)
	{
		abfall[i].render();
	}
}

void huw::level::collision(huw::player& player)
{
	for(int i=0; i<abfall.size(); i++)
	{
		if(huw::collision(*player.m_wolf, abfall[i]))
		{
			if(player.m_wolf->acc.x!=0)
			{
				player.m_wolf->pos.x-=player.m_wolf->acc.x/(abs(player.m_wolf->acc.x));
				player.m_wolf->acc.x=0;
			}
			if(player.m_wolf->acc.y!=0)
			{
				player.m_wolf->pos.y-=player.m_wolf->acc.y/(abs(player.m_wolf->acc.y));
				player.m_wolf->acc.y=0;
			}
		}
		if(huw::collision(*player.m_hase, abfall[i]))
		{
			if(player.m_hase->acc.x!=0)
			{
				player.m_hase->pos.x-=1.05*player.m_hase->acc.x/(abs(player.m_hase->acc.x));
				player.m_hase->acc.x=0;
			}
			if(player.m_hase->acc.y!=0)
			{
				player.m_hase->pos.y-=-1.05*player.m_hase->acc.y/(abs(player.m_hase->acc.y));
				if(player.m_hase->acc.y>0)
				{
					//player.m_hase->pos.y;
					player.m_hase->acc.y=-1.05*GRAVITY*m_game->delta_t;
				}
			}
		}
	}
}