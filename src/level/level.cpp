#include <huw.hpp>

huw::level::level(uint8_t level[11][20], huw::game& game)
{
	for(int iy=0; iy<LEVEL_Y; iy++)
	{
		for(int ix=0; ix<LEVEL_X; ix++)
		{
			std::cout << LEVEL_X << std::endl;
			std::cout << ix << " x " << iy << std::endl; 
			switch(level[iy][ix])
			{
				case ABFALL:
					abfall.push_back(huw::sprite("../assets/Muelltonne.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					abfall[abfall.size()-1].pos.y=iy*PLAYER_SIZE;
					abfall[abfall.size()-1].pos.x=ix*PLAYER_SIZE;
				break;
				case NEON_L:
					neon_l.push_back(huw::sprite("../assets/NeonL.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					neon_l[neon_l.size()-1].pos.x=ix*PLAYER_SIZE;
					neon_l[neon_l.size()-1].pos.y=iy*PLAYER_SIZE;
				break;
				case NEON_M:
					neon_m.push_back(huw::sprite("../assets/NeonM.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					neon_m[neon_m.size()-1].pos.x=ix*PLAYER_SIZE;
					neon_m[neon_m.size()-1].pos.y=iy*PLAYER_SIZE;
				break;
				case NEON_R:
					neon_r.push_back(huw::sprite("../assets/NeonR.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					neon_r[neon_r.size()-1].pos.x=ix*PLAYER_SIZE;
					neon_r[neon_r.size()-1].pos.y=iy*PLAYER_SIZE;
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

	for(int i=0; i<neon_l.size(); i++)
	{
		neon_l[i].render();
	}

		for(int i=0; i<neon_m.size(); i++)
	{
		neon_m[i].render();
	}

		for(int i=0; i<neon_r.size(); i++)
	{
		neon_r[i].render();
	}
}