#include "Bomb.h"
#include "Ball.h"
#include "Board.h"


void Bomb::Move()
{
	ball->move(COLOR::RED_TEXT);
}
//check for ballposition and act acordingly
BallPosition Bomb::Action(Board * board)
{
	// MISSED, CENTER_HIT, CORNER_HIT, AWAY
	int left_X_Dist, right_X_Dist;
	bool ball_location;
	//right half located
	if (ball->get_X_left() >= Point::MID)
		ball_location = true;
	//left half located
	else
		ball_location = false;

	// Finds the right distance of the Ball in accord to the right paddle
	if (ball_location && board->getpos() == BoardPos::right)
	{
		right_X_Dist = board->getX() - ball->get_X_right();
	}
	//defult
	else
		right_X_Dist = 2;

	// Finds the left distance of the Ball in accord to the left paddle
	if (!ball_location && board->getpos() == BoardPos::left)
	{
		left_X_Dist = ball->get_X_left() - board->getX();
	}
	//defult
	else
		left_X_Dist = 2;

	// in this option there is a corner hit opt and a miss opt
	if (left_X_Dist <= 0 || right_X_Dist <= 0) {
		if (ball->getY() + 1 == board->get_up_Y() && ball->getYDirection() == YDirection::Down
			|| ball->getY() - 1 == board->get_down_Y() && ball->getYDirection() == YDirection::Up)
		{
			return BallPosition::BOMB_HIT;
		}
		return BallPosition::MISSED_BOMB;
	}
	//int this option there are a center hit opt, corner hit option
	if (left_X_Dist == 1 || right_X_Dist == 1) {
		if (board->get_up_Y() <= ball->getY() && board->get_down_Y() >= ball->getY())
		{
			return BallPosition::BOMB_HIT;
		}
		else if (ball->getY() + 1 == board->get_up_Y() && ball->getYDirection() == YDirection::Down
			|| ball->getY() - 1 == board->get_down_Y() && ball->getYDirection() == YDirection::Up)
		{
			return BallPosition::BOMB_HIT;
		}
	}
	// If we havent found that the ball has missed or hit the padlle the ball is away
	return BallPosition::AWAY;
}

void Bomb::NextState()
{
	ball->setstate(ball->getregular());
}

void Bomb::PrevState()
{
	ball->setstate(ball->getbecome());
}
