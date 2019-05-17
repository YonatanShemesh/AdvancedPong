#include "Board.h"
#include "KeyBoardListener.h"
extern unsigned long long int game_iteration;
class UserBoard :public Board,public KeyBoardListener
{
private:
	enum { kbup, kbdown, kbbomb};
	const char* characters;
	char currChar = 0;
	bool tomove = false;
	
public:
	UserBoard(Point up1, Point down1, BoardPos position1, const char* ch1) :Board(up1,down1,position1), characters(ch1) {}
	virtual void move(const Ball & ball)override
	{
		if (tomove)
		{
			setColor(COLOR::BLUE_TEXT);
			if (currChar == characters[kbup])
			{
				if (up.getY() != Point::MIN_Y)
				{
					this->move_up();
				}
			}
			else if (currChar == characters[kbdown])
			{
				if (down.getY() != Point::MAX_Y)
				{
					this->move_down();
				}
			}
			tomove = false;
		}
	}
	void handleKey(char c, bool &continuegame, bool &newgame, const Board *L, const Board *R,  Ball &b, const Bricks &brickmanager, difficult & d, Mode & GameMode)
	{
		currChar = c;
		if (currChar == characters[kbup] || currChar == characters[kbdown])
			tomove = true;
		if (currChar == characters[kbbomb])
			if (lastactivate <= game_iteration)
			{
				lastactivate = game_iteration+4;
				ActivateBomb(b);
			}
	}
	void ActivateBomb(Ball &ball)
	{
		ball.Activate();
	}
	const char* getKbChars()
	{
		return characters;
	}
};

