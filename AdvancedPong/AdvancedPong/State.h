#pragma once
#include "Enums.h"
#include "utils.h"
class Ball;
class Board;

//this header will be the abstract base class of the varity of the ball states 
class State
{
protected:
	Ball* ball;
public:
	State(Ball *ball1);//ctor
	virtual ~State() {}//dtor
	virtual void Move() = 0;
	virtual BallPosition Action(Board *board) = 0;
	virtual void NextState() = 0;//move to next state
	virtual void PrevState() = 0;//go to prev state

};
