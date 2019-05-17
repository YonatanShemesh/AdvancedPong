#pragma once
#include "State.h"
//the functions got their implement in the cpp files in the reseon of forward decleration 
class Regular: public State
{
public:
	Regular():State(nullptr) {}
	Regular(Ball *ball1) :State(ball1) {}
	void Move()override;
	BallPosition Action(Board *board)override;
	void NextState()override;
	void PrevState()override;
};