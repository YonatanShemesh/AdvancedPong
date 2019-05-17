#pragma once
#include <iostream>
#include "Board.h"
#include "UserBoard.h"
#include "PcBoard.h"
#include"KeyboardManager.h"
#include"Screen.h"
#include "Bricks.h"
#include <conio.h>
#include "Enums.h"


using namespace std;

extern unsigned long long int game_iteration;

class Game :public KeyBoardListener
{
private:
	const char *characters = "\u001B";//the asci number of escape!!!!!!!
	enum { Escape, Starthh = '1', Starthc = '2',Startcc = '3', Continuegame = '4', Present = '8', EXIT = '9' };
	Screen s;
public:
	//Gives to the KB Manager Game key binds
	const char* getKbChars()
	{
		return characters;
	}
	bool Launch(difficult &dif, Mode & game_mode);
	int pause();
	bool start(difficult & d, Mode & GameMode);
	void handleKey(char c, bool &continuegame, bool &newgame, const Board *L, const Board *R,  Ball &b, const Bricks &brickmanager, difficult & d, Mode & GameMode);
	Board* checkMissed(Board *Lplayer, Board *Rplayer, Ball& ball, bool & missed,  bool & bigmissed, bool & goodmissed, Bricks &bricks);
	void disqualification(Bricks & brick, Board *board, Ball &ball, bool bigmissed, bool & goodmissed);
	bool gameover(Board b);
	void count_game_iteration(const Ball &ball)
	{
		if (ball.get_X_left() + 1 == Point::MID)
		{
			++game_iteration;
		}

	}
	difficult chosedifficult()
	{
		int choise;
		s.choose_difficult();
		choise = _getch() - '0';
		while (choise != 1 && choise != 2 && choise != 3)
		{
			choise = _getch() - '0';
		}
		return (difficult)choise;
	}
	void animateMiss(Board *board, Ball &ball)
	{
		setColor(COLOR::BLUE_TEXT);
		gotoxy(board->getX(), ball.getY());//animation put x on disqualification spot 
		std::cout << 'X';
		Sleep(100);
		gotoxy(board->getX(), ball.getY());
		std::cout << ' ';//end of animation
	}
};