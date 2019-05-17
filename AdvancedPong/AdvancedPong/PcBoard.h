#include "Board.h"

extern unsigned long long int game_iteration;
class PcBoard : public Board {
	
	difficult dif;
	int missPoint;
	bool miss = false;
public:
	PcBoard(Point up1, Point down1, BoardPos position1, difficult dif1):Board(up1,  down1,  position1),dif(dif1){
		if (dif == difficult::GOOD)
		{
			missPoint = rand() % 40;
		}
		else if (dif == difficult::NOVICE)
		{
			missPoint = rand() % 10;
		}
	}
	virtual ~PcBoard() override {};
	virtual void move(const Ball & ball) override;//moves the pcBoard
	void setDif(const difficult& dif1)
	{
		dif = dif1;
		if (dif == difficult::GOOD)
		{
			missPoint = rand() % 40;
		}
		else if (dif==difficult::NOVICE)
		{
			missPoint = rand() % 10;
		}
		else
		{
			missPoint = 0;
		}

	}
	//recenters the paddle after the ball going to the opposite way
	void reCenter() {
		if (this->get_up_Y() + 1 != 14)
		{
			if (this->get_up_Y() + 1 > 14) {
				this->move_up();
			}
			else  {
				this->move_down();
			}
			//Sleep(20);
		}
	}
	//make the pc padlle miss
	void miss_chance(const difficult & dif, const Ball &ball)
	{
		if (dif == difficult::GOOD)
		{
			if ((game_iteration / 2) % 40 == missPoint)
			{
				miss = true;
				missPoint = rand() % 40;
			}
		}
		else if (dif == difficult::NOVICE)
		{
			if ((game_iteration / 2) % 10 == missPoint)
			{
				miss = true;
				missPoint = rand() % 10;
			}
		}
		else
		{
			miss = false;
		}
	}
	void activate(Ball &b,Board board)
	{
		int toactive =1;
		if (game_iteration > lastactivate && (int)b.getXDirection() != (int)getpos()&&board.dis_to_board(b)<=9)
		{
			switch (dif)
			{
			case difficult::NOVICE:
				toactive = rand() % 4;
				break;
			case difficult::GOOD:
				toactive = rand() % 3;
				break;

			case difficult::BEST:
				toactive = rand() % 2;
				break;

			}
			if (!toactive)
			{
				lastactivate = game_iteration + 4;
				b.Activate();
			}
			else
				lastactivate = game_iteration;

		}
	}
};