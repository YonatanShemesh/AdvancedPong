#include "Ball.h"
#include "Screen.h"
#include "Bricks.h"

void Ball::move(COLOR paint)
{
	setColor(paint);
	erase();
	if (Screen::isOn_X_Edge(left)) {
		dir_x *= -1;
	}
	if (Screen::isOn_X_Edge(right)) {
		dir_x *= -1;
	}
	if (Screen::isOn_Y_Edge(left)) {
		dir_y *= -1;
	}
	left.move(dir_x, dir_y);
	right.move(dir_x, dir_y);
	draw();
}
// Erase the Ball menually
void Ball::erase()
{
	Point i = left;

	i.erase();
	i.move(1, 0);
	i.erase();
	i.move(0, -1);
	i.erase();
	i.move(0, 2);
	i.erase();
	i.move(1, -1);
	i.erase();
	i.move(0, -1);
	i.erase();
	i.move(0, 2);
	i.erase();
	i.move(1, -1);
	i.erase();
}
// Draw the Ball menually
void Ball::draw ()const
{
	Point i = left;

	i.draw();
	i.move(1, 0);
	i.draw();
	i.move(0, -1);
	i.draw();
	i.move(0, 2);
	i.draw();
	i.move(1, -1);
	i.draw();
	i.move(0, -1);
	i.draw();
	i.move(0, 2);
	i.draw();
	i.move(1, -1);
	i.draw();
}
// Animate the ball when hitting the left baord
void Ball::animate_left(YDirection dir)
{
	setColor(COLOR::GRAY_TEXT);
	Point i = left;

	//going up
	if (dir== YDirection::Up)
	{
		//first hit
		i.move(0, -1);
		i.draw();
		i.move(0, 2);
		i.draw();
		i.move(1, 0);
		i.erase();
		i.move(1, 0);
		i.erase();
		i.move(0, -2);
		i.erase();
		i.move(1, 1);
		i.erase();
		Sleep(60);
		i = left;
		//second hit 
		i.move(0, 1);
		i.erase();
		i.move(2, -1);
		i.erase();
		i.move(0, -1);
		i.draw();
		i.move(1, 0);
		i.draw();
		i.move(-1, -1);
		i.draw();
		i.move(-1, 0);
		i.draw();
		Sleep(60);
		//go back
		i = left;
		i.erase();
		i.move(1, 0);
		i.erase();
		i.move(-1, -1);
		i.erase();
		i.move(3, 0);
		i.erase();
		left.move(0, -2);
		right.move(0, -2);
	}
	//going down
	else
	{
		//first hit
		i.move(0, -1);
		i.draw();
		i.move(0, 2);
		i.draw();
		i.move(2, 0);
		i.erase();
		i.move(0, -2);
		i.erase();
		i.move(-1, 0);
		i.erase();
		i.move(2, 1);
		i.erase();
		Sleep(60);
		i = left;
		//second hit 
		i.move(0, -1);
		i.erase();
		i.move(2, 1);
		i.erase();
		i.move(0, 1);
		i.draw();
		i.move(1, 0);
		i.draw();
		i.move(-1, 1);
		i.draw();
		i.move(-1, 0);
		i.draw();
		Sleep(60);
		//go back
		i = left;
		i.erase();
		i.move(1, 0);
		i.erase();
		i.move(-1, 1);
		i.erase();
		i.move(3, 0);
		i.erase();
		left.move(0, 2);
		right.move(0, 2);

	}
}
// Animate the ball when hitting the right baord
void Ball::animate_right(YDirection dir)
{
	setColor(COLOR::GRAY_TEXT);
	Point i = right;

	//going up
	if (getYDirection()== YDirection::Up)
	{
		//first hit
		i.move(0, -1);
		i.draw();
		i.move(0, 2);
		i.draw();
		i.move(-1, 0);
		i.erase();
		i.move(-1, 0);
		i.erase();
		i.move(0, -2);
		i.erase();
		i.move(-1, 1);
		i.erase();
		Sleep(60);
		i = right;
		//second hit 
		i.move(0, 1);
		i.erase();
		i.move(-2, -1);
		i.erase();
		i.move(0, -1);
		i.draw();
		i.move(-1, 0);
		i.draw();
		i.move(1, -1);
		i.draw();
		i.move(1, 0);
		i.draw();
		Sleep(60);
		//go back
		i = right;
		i.erase();
		i.move(-1, 0);
		i.erase();
		i.move(1, -1);
		i.erase();
		i.move(-3, 0);
		i.erase();
		right.move(0, -2);
		left.move(0, -2);
	}
	else
	{
		//first hit
		i.move(0, -1);
		i.draw();
		i.move(0, 2);
		i.draw();
		i.move(-2, 0);
		i.erase();
		i.move(0, -2);
		i.erase();
		i.move(1, 0);
		i.erase();
		i.move(-2, 1);
		i.erase();
		Sleep(60);
		i = right;
		//second hit 
		i.move(0, -1);
		i.erase();
		i.move(-2, 1);
		i.erase();
		i.move(0, 1);
		i.draw();
		i.move(-1, 0);
		i.draw();
		i.move(1, 1);
		i.draw();
		i.move(1, 0);
		i.draw();
		Sleep(60);
		//go back
		i = right;
		i.erase();
		i.move(-1, 0);
		i.erase();
		i.move(1, 1);
		i.erase();
		i.move(-3, 0);
		i.erase();
		right.move(0, 2);
		left.move(0, 2);
	}
}
//re draw the ball at the starting position and generates a new random direction for start
void Ball::reset()
{
	Ballstate = &regular;
	left = { 40,12,'O' };
	right = { 43,12,'O' };
	dir_x = (rand() % 2) * 2 - 1;
	dir_y = (rand() % 2) * 2 - 1;
	draw();
}

bool Ball::checkforbricks(Bricks *bricks,Board &board,int &line)
{
	if (board.getpos() == BoardPos::right && get_X_right()>=board.getX())
	{
		for (auto i : bricks->Bklist[Bricks::right])
		{
			if (i.getX() - 1 == get_X_right())
			{
				if (getY() >= i.get_up_Y() && getY() <= i.get_down_Y())
				{
					line = abs((Bricks::MAX_X + 1)*(int)(i.getpos()) - i.getX());
					return true;
				}
			}
			else if (i.getX() == get_X_right())
			{
				if (getY() == i.get_up_Y()-1 || getY() == i.get_down_Y()+1)
				{
					line = abs((Bricks::MAX_X + 1)*(int)(i.getpos()) - i.getX());
					return true;
				}
			}
		}
	}
	else if(board.getpos() == BoardPos::left && get_X_left() <= board.getX())
	{
		for (auto i : bricks->Bklist[Bricks::left])
		{
			if (i.getX() + 1 == get_X_left())
			{
				if (getY() >= i.get_up_Y() && getY() <= i.get_down_Y())
				{
					line = abs((Bricks::MAX_X + 1)*(int)(i.getpos()) - i.getX());
					return true;
				}
			}
			else if (i.getX() == get_X_left())
			{
				if (getY() == i.get_up_Y() - 1 || getY() == i.get_down_Y() + 1)
				{
					line = abs((Bricks::MAX_X + 1)*(int)(i.getpos()) - i.getX());
					return true;
				}
			}
		}
	}
	else
		return false;


	 
}


