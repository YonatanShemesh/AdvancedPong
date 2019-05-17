#include "Board.h"

void Board::draw()const
{
	setColor(COLOR::BLUE_TEXT);
	Point i = up;
	i.draw();
	while (i.getY() != down.getY())
	{
		i.move(0, 1);
		i.draw();
	}
}



// Return the location of the ball ( if there was a miss, the ball is away, center hit or corner hit)
BallPosition Board::checkBallPosition(const Ball & ball)
{
	return ball.Action(this);
}

// the Board movement 
void Board::verticalmove(BoardPos pos1)
{
	setColor(COLOR::BLUE_TEXT);
	if (pos1 == BoardPos::left)
	{
		down.erase();
		down.move(-1, 0);
		up.erase();
		up.move(0, 1);
		up.erase();
		up.move(-1, -1);

		Point i = up;
		i.draw();
		while (i.getY() != down.getY())
		{
			i.move(0, 1);
			i.draw();
		}
	}
	else
	{
		down.erase();
		down.move(1, 0);
		up.erase();
		up.move(0, 1);
		up.erase();
		up.move(1, -1);

		Point i = up;
		i.draw();
		while (i.getY() != down.getY())
		{
			i.move(0, 1);
			i.draw();
		}
	}
}



