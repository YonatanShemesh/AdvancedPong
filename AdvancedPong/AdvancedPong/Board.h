#pragma once
#include "Point.h"
#include <cstring>
#include "Ball.h"
#include "utils.h"
#include "Enums.h"
class Bricks;

class Board 
{
protected:
	
	friend class Game;
	friend class Bricks;
	unsigned long long int lastactivate = 0;
	Point up, down;
	int life = 16;
	// The position of the current paddle
	BoardPos position;
public:
	//Ctor that make the board when the game open
	Board(Point up1, Point down1, BoardPos position1) :up(up1), down(down1), position(position1) {}
	//empty constructor for ease
	Board() {}
	virtual ~Board() {};

	void draw()const;
	virtual void move(const Ball & ball) {};
	//update the life status
	void setlife(int n)
	{
		life += n;
	}
	int getlife()const
	{
		return life;
	}

	void move_up() {
		down.erase();
		down.move(0, -1);
		up.move(0, -1);
		up.draw();
	}
	void move_down() {
		up.erase();
		up.move(0, 1);
		down.move(0, 1);
		down.draw();
	}

	void erase()
	{
		up.erase();
		up.move(0, 1);
		up.erase();
		up.move(0, -1);
		down.erase();
	}
	

	

	int getX()const {
		return up.getX();
	}

	int get_up_Y()const {
		return up.getY();
	}

	int get_down_Y()const {
		return down.getY();
	}
	//finds out the ball moving direction
	bool getBall_dir(const Ball & ball)
	{
		if (ball.getXDirection() == XDirection::Right)
		{
			return true;
		}
		return false;
	}
	//finds the distance between the ball and the board
	int dis_to_board(const Ball&ball) {
		if (getpos() == BoardPos::right) {
			return getX() - ball.get_X_right();
		}
		else
		{
			return ball.get_X_left() - getX();
		}
	}
	//Get the Board Pos
	BoardPos getpos()const
	{
		return position;
	}

	BallPosition checkBallPosition(const Ball& ball);
	
	void verticalmove(BoardPos pos1);

};