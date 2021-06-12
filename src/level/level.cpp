#include <huw.hpp>

huw::level::level(uint8_t level[21][11], huw::game& game)
{
	for(int iy=0; iy<LEVEL_Y; iy++)
	{
		for(int ix=0; ix<LEVEL_X; ix++)
		{
			std::cout << LEVEL_X << std::endl;
			std::cout << ix << " x " << iy << std::endl; 
			switch(level[ix][iy])
			{
				case ABFALL:
					abfall.push_back(huw::sprite("../assets/Muelltonne.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE));
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