#pragma once
#include <iostream>
#include "utils.h"
class Point
{
private:
	int x, y;
	int dir_x;
	int dir_y;
	char ch;
	friend class Screen;
public:
	// Screen Boarders
	enum { MAX_Y = 24, MIN_Y = 4, MAX_X = 79, MIN_X = 1 ,MID=40};
	// Empty Ctor
	Point() {}
	// Ctor
	Point(int x1, int y1, char ch1) :x(x1), y(y1), ch(ch1) {}
	// Draw the point
	void draw()const
	{
		gotoxy(x, y);
		std::cout << ch;
	}
	// Erase the point
	void erase()
	{
		gotoxy(x, y);
		std::cout << " ";
	}

	void move(int, int);
	// Get Y cord
	int getY()const
	{
		return y;
	}
	// Get X cord
	int getX()const
	{
		return x;
	}
};
