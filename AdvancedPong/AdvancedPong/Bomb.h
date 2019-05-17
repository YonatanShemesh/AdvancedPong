#pragma once
#include "State.h"
//the functions got their implement in the cpp files in the reson of forward decleration 
class Bomb: public State
{
public:
	Bomb():State(nullptr) {}
	Bomb(Ball *ball1) :State(ball1) {}
	void Move()override;
	BallPosition Action(Board *board)override;
	void NextState()override;
	void PrevState()override;

};