
#pragma once
#include "Point.h"
#include "utils.h"
#include "Enums.h"
#include "State.h"
#include "Regular.h"
#include "BecomeBomb.h"
#include "Bomb.h"
class Bricks;

//class ball use class point to describe the ball
class Ball {
private:
	Point left, right;
	Regular regular;
	BecomeBomb become;
	Bomb bomb;
	State *Ballstate;
	//Creates a Random start direction
	int dir_x = (rand() % 2) * 2 - 1;
	int dir_y = (rand() % 2) * 2 - 1;
public:
	//Ctor
	Ball(Point p, Point p1) : left(p), right(p1), regular(this), become(this), bomb(this), Ballstate(&regular) {}
	void move(COLOR paint);
	void move()
	{
		Ballstate->Move();
	}
	BallPosition Action(Board *board)const
	{
		return Ballstate->Action(board);
	}
	void Activate()
	{
		Ballstate = &become;
	}
	void erase();
	void draw()const;
	//animate the ball at the left board
	void animate_left(YDirection dir);
	//animate the ball at the right board
	void animate_right(YDirection dir);
	//get Y cord
	int getY()const {
		return left.getY();
	}
	int get_X_left()const {
		return left.getX();
	}
	int get_X_right()const {
		return right.getX();
	}
	void changeYDirection() {
		dir_y *= -1;
	}
	void changeXDirection() {
		dir_x *= -1;
	}

	//Finds out the ball Moving direction in the Y scale
	YDirection getYDirection() const {
		return dir_y == -1 ? YDirection::Up : YDirection::Down;
	}
	//Finds out the ball Moving direction in the X scale
	XDirection getXDirection() const {
		return dir_x == 1 ? XDirection::Right : XDirection::Left;
	}
	void reset();
	//set the ball state
	void setstate(State* newstate)
	{
		Ballstate = newstate;
	}
	//returns reg state
	State* getregular()
	{
		return &regular;
	}
	//returns become state
	State* getbecome()
	{
		return &become;
	}
	//returns bomb state
	State* getbomb()
	{
		return &bomb;
	}
	//checks the ball state
	State* getstate()
	{
		return Ballstate;
	}
	//check if there is dead brickes when the ball cross the paddle line 
	bool checkforbricks(Bricks *bricks, Board &board,int &line);
};