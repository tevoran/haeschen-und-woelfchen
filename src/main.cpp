#include <huw.hpp>
#include <level/actual_levels.hpp>

#undef main



int main(int argc, char *argv[])
{
	SDL_Color text_color={45, 44, 44, 0};

	huw::game game;
	huw::sprite background("../assets/DarkGhetto.png", & game, 0, 0, 640, 360, RESX, RESY);
	huw::sprite hase("../assets/Haeschen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::sprite wolf("../assets/Woelfchen1.png", &game, 0, 0, 32, 32, PLAYER_SIZE, PLAYER_SIZE);
	huw::player player(&hase, &wolf, &game);
	huw::level level(huw::level1, &game);

	//text preparation
	text_color={228,20,228,0};

	huw::text wall_text1(&game, "HAESCHEN", text_color, true);
	huw::text wall_text2(&game, "WOELFCHEN", text_color, true);
	huw::text tut_text1(&game, "W:JUMP  D:MOVE RIGHT  A:MOVE LEFT", text_color, false);	

	bool quit=false;
	while(!quit)
	{
		background.render();
		level.render();
		player.update(); //muss vor der level kollision sein
		level.collision(player);
		wall_text1.render((int)(0.125*(float)RESX),(int)(0.375*(float)RESY));
		wall_text2.render((int)(0.64*(float)RESX),(int)(0.485*(float)RESY));
		tut_text1.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		game.update(quit);
	}
}