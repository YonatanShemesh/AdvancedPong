#include "PcBoard.h"

void PcBoard::move(const Ball & ball)
{
	miss_chance(dif,ball);//if there is a need to miss by the pc Board lvl.
	int distance = dis_to_board(ball);
	bool ball_location=getBall_dir(ball);
	//if its the right padlle
	setColor(COLOR::BLUE_TEXT);
	if (getpos() == BoardPos::right ) {
		//if the Ball is Moving right and the ball croosed the mid board 
		if (ball_location && ball.get_X_left()>= Point::MID)
		{
			if (distance <= 1 && miss)
			{
				if (ball.getYDirection() == YDirection::Up && get_down_Y() != Point::MAX_Y)
				{
					move_down();
				}
				else
				{
					if(get_up_Y() != Point::MIN_Y)
						move_up();
				}
				miss = false;
			}
			else
			{
				//move the Board up
				if (get_up_Y()+1 > ball.getY() && get_up_Y()-1 != Point::MIN_Y)
				{
					move_up();
				}
				//move the Board Down
				else if(get_up_Y() + 1 < ball.getY() && get_down_Y()+1 != Point::MAX_Y)
				{
						move_down();
				}
			}
		}
		else
			reCenter();
	}
	//if its the left Board
	else {
		//if the Ball is Moving Left and the ball croosed the mid board
		if (!ball_location && ball.get_X_left() < Point::MID)
		{
			if (distance <= 1 && miss) {
				if (ball.getYDirection() == YDirection::Up)
				{
					move_down();
				}
				else
				{
					move_up();
				}
				miss = false;
			}
			else
			{
				//move the Board up
				if (get_up_Y()+1 > ball.getY() && get_up_Y()-1 != Point::MIN_Y)
				{
					move_up();
				}
				//move the Board Down
				
				else if (get_up_Y() + 1 < ball.getY() && get_down_Y()+1 != Point::MAX_Y)
				{
					move_down();
				}
			}
		}
		else
			reCenter();

	}
}
