#include <iostream>
#include"Point.h"
#include"Board.h"
#include "KeyboardManager.h"
#include"Screen.h"
#include"Game.h"

using namespace std;

void main()
{
	bool game;
	Game g;
	difficult dif= difficult::BEST;
	Mode game_mode;
	game = g.Launch(dif,game_mode);
	while (game)
	{
		game = g.start(dif, game_mode);
	}
}




                            