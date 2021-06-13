#include <huw.hpp>


void huw::level_scripts(int current_level, huw::game& game)
{
	SDL_Color TEXT_COLOR={228,20,228,0};

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


	//tutorial
	if(current_level==0)
	{
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
		static float intro_text=0;
		intro_text+=game.delta_t;

		if(intro_text<4)
		{
			tut_text7.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}
		if(intro_text<8 && intro_text>4)
		{
			tut_text8.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}
		if(intro_text<12 && intro_text>8)
		{
			tut_text9.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}
		if(intro_text<16 && intro_text>12)
		{
			tut_text10.render((int)(0.1*(float)RESX),(int)(0.025*(float)RESY));
		}
		if(intro_text>16)
		{
			intro_text=0;
		}
	}

}