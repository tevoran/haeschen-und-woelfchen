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
	text_color={228,225,228,0};

	huw::text intro_text1(&game, "HAESCHEN", text_color);
	huw::text intro_text2(&game, "WOELFCHEN", text_color);

	bool quit=false;
	while(!quit)
	{
		background.render();
		level.render();
		player.update(); //muss vor der level kollision sein
		level.collision(player);
		intro_text1.render((int)(0.125*(float)RESX),(int)(0.375*(float)RESY));
		intro_text2.render((int)(0.64*(float)RESX),(int)(0.485*(float)RESY));
		game.update(quit);
	}
}