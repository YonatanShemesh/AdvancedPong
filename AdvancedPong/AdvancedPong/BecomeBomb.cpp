#include "BecomeBomb.h"
#include "Ball.h"
#include "Board.h"



void BecomeBomb::Move()
{
	ball->move(COLOR::PINK_FADE_TEXT);
}
//check for ballposition and act acordingly
BallPosition BecomeBomb::Action(Board * board)
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
			return BallPosition::CORNER_HIT_BE;
		}
		return BallPosition::MISSED_BE;
	}
	//int this option there are a center hit opt, corner hit option
	if (left_X_Dist == 1 || right_X_Dist == 1) {
		if (board->get_up_Y() <= ball->getY() && board->get_down_Y() >= ball->getY())
		{
			return BallPosition::CENTER_HIT_BE;
		}
		else if (ball->getY() + 1 == board->get_up_Y() && ball->getYDirection() == YDirection::Down
			|| ball->getY() - 1 == board->get_down_Y() && ball->getYDirection() == YDirection::Up)
		{
			return BallPosition::CORNER_HIT_BE;
		}
	}
	// If we havent found that the ball has missed or hit the padlle the ball is away
	return BallPosition::AWAY;
}

void BecomeBomb::NextState()
{
	ball->setstate(ball->getbomb());
}

void BecomeBomb::PrevState()
{
	ball->setstate(ball->getregular());

}
