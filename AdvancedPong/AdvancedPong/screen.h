#pragma once
#include "Board.h"
#include"Point.h"
#include "Bricks.h"

class Screen
{
private:
public:
	// Screen Borders
	enum { MAX_Y = 24, MIN_Y = 4, MAX_X = 79, MIN_X = 1 };
	void ClearScreen();
	void MakeLayout();
	void Redrawgame(const Board *L, const Board *R, const Ball &b, const Bricks &brickmanager);
	void launch();
	void gameover();
	void present();
	void start();
	void choose_difficult();
	
	void drawLifes(const Board *L, const Board *R) {
		gotoxy(0, 26);
		setColor(COLOR::YELLOW_FADE_TEXT);
		std::cout << "                                                                                                    ";
		gotoxy(0, 26);
		std::cout << "Lifes: " << L->getlife() << "								Lifes: " << R->getlife();
	}
	static bool isOn_Y_Edge(const Point& p) {
		return (p.y) - 1 == MIN_Y || (p.y) + 1 == MAX_Y;
	}

	static bool isOn_X_Edge(const Point& p) {
		return p.x == MIN_X || p.x == MAX_X;
	}
};