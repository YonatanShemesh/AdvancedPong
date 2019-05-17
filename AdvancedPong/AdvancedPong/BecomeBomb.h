#pragma once
#include "State.h"

//the functions got their implement in the cpp files in the reson of forward decleration 
class BecomeBomb :public State
{
public:
	BecomeBomb():State(nullptr) {}//ctor
	BecomeBomb(Ball *ball1) :State(ball1) {}//copy ctor
	void Move()override;
	//the same action as the state header
	BallPosition Action(Board *board)override;
	void NextState()override;
	void PrevState()override;

};