#include <huw.hpp>

huw::level::level(uint8_t level[11][20], huw::game *game, huw::player& player)
{
	m_game=game;
	for(int iy=0; iy<LEVEL_Y; iy++)
	{
		for(int ix=0; ix<LEVEL_X; ix++)
		{
			switch(level[iy][ix])
			{
				case ABFALL:
					abfall.push_back(huw::sprite("../assets/Muelltonne.png", m_game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					abfall[abfall.size()-1].pos.y=iy*PLAYER_SIZE;
					abfall[abfall.size()-1].pos.x=ix*PLAYER_SIZE;
				break;
				case NEON_L:
					neon_l.push_back(huw::sprite("../assets/NeonL.png", m_game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					neon_l[neon_l.size()-1].pos.x=ix*PLAYER_SIZE;
					neon_l[neon_l.size()-1].pos.y=iy*PLAYER_SIZE;
				break;
				case NEON_M:
					neon_m.push_back(huw::sprite("../assets/NeonM.png", m_game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					neon_m[neon_m.size()-1].pos.x=ix*PLAYER_SIZE;
					neon_m[neon_m.size()-1].pos.y=iy*PLAYER_SIZE;
				break;
				case NEON_R:
					neon_r.push_back(huw::sprite("../assets/NeonR.png", m_game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					neon_r[neon_r.size()-1].pos.x=ix*PLAYER_SIZE;
					neon_r[neon_r.size()-1].pos.y=iy*PLAYER_SIZE;
				break;
				case TAUBE:
					taube.push_back(huw::sprite("../assets/Taube2.png", m_game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					taube[taube.size()-1].pos.x=ix*PLAYER_SIZE;
					taube[taube.size()-1].pos.y=iy*PLAYER_SIZE;

					//parameter hinzufügen
					taube_richtung.push_back(false); //links
				break;
				case GHETTO:
					ghetto.push_back(huw::sprite("../assets/GhettoOffNeon.png", m_game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					ghetto[0].pos.x=ix*PLAYER_SIZE;
					ghetto[0].pos.y=iy*PLAYER_SIZE;

					ghetto.push_back(huw::sprite("../assets/GhettoOnNeon.png", m_game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					ghetto[1].pos.x=ix*PLAYER_SIZE;
					ghetto[1].pos.y=iy*PLAYER_SIZE;
				break;

				case WOLF:
					player.m_wolf->pos.x=ix*PLAYER_SIZE;
					player.m_wolf->pos.y=iy*PLAYER_SIZE;
				break;

				case HASE:
					player.m_hase->pos.x=ix*PLAYER_SIZE;
					player.m_hase->pos.y=iy*PLAYER_SIZE;
				break;
			}
		}
	}
}

void huw::level::render()
{
	for(unsigned int i=0; i<abfall.size(); i++)
	{
		abfall[i].render();
	}
	for(unsigned int i=0; i<neon_l.size(); i++)
	{
		neon_l[i].render();
	}

	for(unsigned int i=0; i<neon_m.size(); i++)
	{
		neon_m[i].render();
	}

	for(unsigned int i=0; i<neon_r.size(); i++)
	{
		neon_r[i].render();
	}

	for(unsigned int i=0; i<taube.size(); i++)
	{
		taube[i].render();
	}

	if(!activated){
		ghetto[0].render();
	}
	else{
		ghetto[1].render();
	}
}

void huw::level::enemy_update()
{
	for(int i=0; i<taube.size(); i++)
	{
		bool collision_with_trash=false;
		for(int i_tmp=0; i_tmp<abfall.size(); i_tmp++)
		{
			if(huw::collision(taube[i], abfall[i_tmp]))
			{
				collision_with_trash=true;
			}
		}
		if(collision_with_trash==true)
		{
			taube_richtung[i]=(!taube_richtung[i]);
		}
		if(taube_richtung[i]==false) //links
		{
			taube[i].pos.x-=TAUBE_SPEED*m_game->delta_t;
		}
		else
		{
			taube[i].pos.x+=TAUBE_SPEED*m_game->delta_t;
		}
	}
}

void huw::level::collision(huw::player& player){
	check_coll(player, neon_l);
	check_coll(player, neon_m);
	check_coll(player, neon_r);
	check_coll(player, abfall);
	if(check_coll(player, taube)){
		//std::cout << "RIP" << std::endl;
	}
	if(huw::collision(*player.m_hase, ghetto[0]) && m_game->keyboard_state[SDL_SCANCODE_E] && !activated){
		std::cout << "aktiviert" << std::endl;
		activated=true;
	}
	if(player.m_active_char->pos.y+PLAYER_SIZE>=RESY)
	{
		player.can_jump=true;
	}
}

bool huw::level::check_coll(huw::player& player, std::vector<huw::sprite> &objects){
	bool collided_wolf=false;
	bool collided_hase=false;
	for(int i=0; i<objects.size(); i++)
	{
		if(huw::collision(*player.m_wolf, objects[i]))
		{
			collided_wolf=false;
			//von oben 
			if(player.m_wolf->acc.y>0 && player.m_wolf_y_plus==false)
			{
				player.m_wolf->pos.y-=player.m_wolf->acc.y*m_game->delta_t;
				player.m_wolf->acc.y=-GRAVITY*m_game->delta_t;
				collided_wolf=true;
				player.m_wolf_y_plus=true;
				if(player.m_active_char==player.m_wolf)
				{
					player.can_jump=true;					
				}
			}
			//von unten
			if(player.m_wolf->acc.y<0 && collided_wolf==false  && player.m_wolf_y_minus==false && player.m_wolf_y_plus==false) 
			{
				player.m_wolf->pos.y-=player.m_wolf->acc.y*m_game->delta_t;
				player.m_wolf->acc.y=0;
				player.m_wolf_y_minus=true;
			}

			//von links
			if(player.m_wolf->acc.x>0 && player.m_wolf->acc.y==0 && player.m_wolf_x_plus==false)
			{
				player.m_wolf->pos.x-=player.m_wolf->acc.x/(abs(player.m_wolf->acc.x));
				player.m_wolf->acc.x=0;
				player.m_wolf->acc.y=-GRAVITY*m_game->delta_t;
				player.m_wolf_x_plus=true;
			}
			//von rechts
			if(player.m_wolf->acc.x<0 && player.m_wolf->acc.y==0 && player.m_wolf_x_minus==false)
			{
				player.m_wolf->pos.x-=player.m_wolf->acc.x/(abs(player.m_wolf->acc.x));
				player.m_wolf->acc.x=0;
				player.m_wolf->acc.y=-GRAVITY*m_game->delta_t;
				player.m_wolf_x_minus=true;
			}
		}
		if(huw::collision(*player.m_hase, objects[i]))
		{
			collided_hase=false;
			//von oben
			if(player.m_hase->acc.y>0 && player.m_hase_y_plus==false)
			{
				player.m_hase->pos.y-=player.m_hase->acc.y*m_game->delta_t;
				player.m_hase->acc.y=-GRAVITY*m_game->delta_t;
				collided_hase=true;
				player.m_hase_y_plus=true;
				if(player.m_active_char==player.m_hase)
				{
					player.can_jump=true;					
				}
			}
			//von unten
			if(player.m_hase->acc.y<0 && collided_hase==false && player.m_hase_y_minus==false && player.m_hase_y_plus==false)
			{
				player.m_hase->pos.y-=player.m_hase->acc.y*m_game->delta_t;
				player.m_hase->acc.y=0;
				player.m_hase_y_minus=true;
			}

			//von links
			if(player.m_hase->acc.x>0 && player.m_hase->acc.y==0 && player.m_hase_x_plus==false)
			{
				player.m_hase->pos.x-=player.m_hase->acc.x/(abs(player.m_hase->acc.x));
				player.m_hase->acc.x=0;
				player.m_hase->acc.y=-GRAVITY*m_game->delta_t;
				player.m_hase_x_plus=true;
			}
			//von rechts
			if(player.m_hase->acc.x<0 && player.m_hase->acc.y==0 && player.m_hase_x_minus==false)
			{
				player.m_hase->pos.x-=player.m_hase->acc.x/(abs(player.m_hase->acc.x));
				player.m_hase->acc.x=0;
				player.m_hase->acc.y=-GRAVITY*m_game->delta_t;
				player.m_hase_x_minus=true;
			}
		}
	}
	if(collided_hase || collided_wolf){
		return true;
	}
	return false;
}