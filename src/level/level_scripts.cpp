#include <huw.hpp>


void huw::level_scripts(int current_level, huw::game& game)
{
	SDL_Color TEXT_COLOR={228,20,228,0};


	static huw::text level0(&game, "LEVEL 0", TEXT_COLOR, false);
	static huw::text level1(&game, "LEVEL 1", TEXT_COLOR, false);
	static huw::text level2(&game, "LEVEL 2", TEXT_COLOR, false);
	static huw::text level3(&game, "LEVEL 3", TEXT_COLOR, false);


	static huw::text tut_text1(&game, "!  WELCOME  TO  HAESCHEN  AND  WOELFCHEN  !", TEXT_COLOR, true);
	static huw::text tut_text2(&game, "!  MOVE  WITH  THE  KEYS  A  AND  D  !", TEXT_COLOR, true);
	static huw::text tut_text3(&game, "!  JUMP  WITH  W  !", TEXT_COLOR, true);
	static huw::text tut_text4(&game, "!  CHANGE  CHARACTER  WITH  LEFT  SHIFT  !", TEXT_COLOR, true);
	static huw::text tut_text5(&game, "!  USE  A  GHETTO  BLASTER  WITH  E  !", TEXT_COLOR, true);
	static huw::text tut_text6(&game, "!  PAY  RESPECT  WITH  F  !", TEXT_COLOR, true);

	static huw::text tut_text7(&game, "!  BEWARE OF THE PIGEONS  !", TEXT_COLOR, true);
	static huw::text tut_text8(&game, "!  ONCE THE GHETTO BLASTER IS ACTIVATED  !", TEXT_COLOR, true);
	static huw::text tut_text9(&game, "!  LITTLE WOLF CAN EAT TRASH CANS  !", TEXT_COLOR, true);
	static huw::text tut_text10(&game, "!  AND BEAT PIGEONS  !", TEXT_COLOR, true);

	static huw::text tut_text11(&game, "HAESCHEN  UND  WOELFCHEN", TEXT_COLOR, true);
	static huw::text tut_text12(&game, "IDEA  BY  TEAM  TOTE  TAUBE", TEXT_COLOR, true);
	static huw::text tut_text13(&game, "PROGRAMMING:  JOHANNES  PFEIFFER  /  T3V", TEXT_COLOR, true);
	static huw::text tut_text14(&game, "PROGRAMMING:  LAURENT  KUFFERT  /  BAKASILISK", TEXT_COLOR, true);
	static huw::text tut_text15(&game, "ART:  HANNA EBNER  /  BIRALO", TEXT_COLOR, true);
	static huw::text tut_text16(&game, "LEVEL  DESIGN:  SVEN  SEEFELD  /  IMPETO94", TEXT_COLOR, true);
	static huw::text tut_text17(&game, "FOOD  SUPPORT:  SVEN  SEEFELD  /  IMPETO94", TEXT_COLOR, true);
	static huw::text tut_text18(&game, "PRESS  ESC  TO  END", TEXT_COLOR, true);

	//tutorial
	if(current_level==0)
	{
		level0.render((int)(0.92*(float)RESX),(int)(0.02*(float)RESY));

		
		static float intro_text=0;
		intro_text+=game.delta_t;
		if(intro_text<4)
		{
			tut_text1.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}

		if(intro_text<9 && intro_text>4)
		{
			tut_text2.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}

		if(intro_text<14 && intro_text>9)
		{
			tut_text3.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}

		if(intro_text<19 && intro_text>14)
		{
			tut_text4.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}

		if(intro_text<24 && intro_text>19)
		{
			tut_text5.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}

		if(intro_text<28 && intro_text>24)
		{
			tut_text6.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}

		if(intro_text>28)
		{
			intro_text=4;
		}
	}

	if(current_level==1)
	{
		level1.render((int)(0.92*(float)RESX),(int)(0.02*(float)RESY));

		static float intro_text=0;
		intro_text+=game.delta_t;

		if(intro_text<4)
		{
			tut_text7.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}
		if(intro_text<8 && intro_text>4)
		{
			tut_text8.render((int)(0.1*(float)RESX),(int)(0.225*(float)RESY));
		}
		if(intro_text<12 && intro_text>8)
		{
			tut_text9.render((int)(0.1*(float)RESX),(int)(0.425*(float)RESY));
		}
		if(intro_text<16 && intro_text>12)
		{
			tut_text10.render((int)(0.1*(float)RESX),(int)(0.625*(float)RESY));
		}
		if(intro_text>16)
		{
			intro_text=0;
		}
	}

	if(current_level==4)
	{
		static float intro_text=0;
		intro_text+=game.delta_t;

		while(!(game.keyboard_state[SDL_SCANCODE_ESCAPE]))
		{
					SDL_RenderPresent(game.m_renderer);
					SDL_RenderClear(game.m_renderer);
					tut_text11.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
					tut_text12.render((int)(0.1*(float)RESX),(int)(0.125*(float)RESY));
					tut_text13.render((int)(0.1*(float)RESX),(int)(0.225*(float)RESY));
					tut_text14.render((int)(0.1*(float)RESX),(int)(0.325*(float)RESY));
					tut_text15.render((int)(0.1*(float)RESX),(int)(0.425*(float)RESY));
					tut_text16.render((int)(0.1*(float)RESX),(int)(0.525*(float)RESY));
					tut_text17.render((int)(0.1*(float)RESX),(int)(0.625*(float)RESY));
					tut_text18.render((int)(0.1*(float)RESX),(int)(0.725*(float)RESY));
				while(SDL_PollEvent(&game.m_event))
				{
				}
		}
	}

	if(current_level==2)
	{
		level2.render((int)(0.92*(float)RESX),(int)(0.02*(float)RESY));
	}

	if(current_level==3)
	{
		level3.render((int)(0.92*(float)RESX),(int)(0.02*(float)RESY));
	}
}