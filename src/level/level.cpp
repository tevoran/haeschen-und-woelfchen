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
				case NEON:
					neon.push_back(huw::sprite("../assets/Leuchtreklame.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
					neon[neon.size()-1].pos.x=ix*PLAYER_SIZE;
					neon[neon.size()-1].pos.y=iy*PLAYER_SIZE;
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

	for(int i=0; i<neon.size(); i++)
	{
		neon[i].render();
	}
}