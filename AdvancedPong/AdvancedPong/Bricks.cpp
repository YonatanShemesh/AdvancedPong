#include "Bricks.h"
//this function check if the way is clear to continue the falling progess 
void Bricks::Fall(Board brick)
{
	bool allownextstep = true;
	while (allownextstep)
	{
		Sleep(150);
		//if its the left Padlle
		if (brick.getpos() == BoardPos:: left)
		{
			//if There are  Dead Padlles Finds out if there is a clear path to go forward
			if (!(Bklist[left].empty()))
			{
				for (auto b : Bklist[left])
				{
					if (brick.getX() == 1 || b.getX() + 1 == brick.getX())
						if (brick.getX() == 1 || b.get_up_Y() <= brick.get_down_Y() && b.get_down_Y() >= brick.get_down_Y() || b.get_down_Y() >= brick.get_up_Y() && b.get_up_Y() <= brick.get_up_Y())//is he going to hit in the next move
							allownextstep = false;
				}
			}
			//There are no Dead Padlles
			else
			{
				if (((brick.getX()) == 1))
					allownextstep = false;
			}
		}
		//The same to the Right Padlle
		else
		{
			if (!(Bklist[right].empty()))
			{
				for (auto b : Bklist[right])
				{
					if (brick.getX() == 79 || b.getX() - 1 == brick.getX())
						if (brick.getX() == 79 || b.get_up_Y() <= brick.get_down_Y() && b.get_down_Y() >= brick.get_down_Y() || b.get_down_Y() >= brick.get_up_Y() && b.get_up_Y() <= brick.get_up_Y())
							allownextstep = false;
				}
			}
			else
			{
				if (brick.getX() == 79)
					allownextstep = false;
			}
		}
		if (allownextstep)
			brick.verticalmove(brick.getpos());
	}
	Addbrick(brick);
}

//this function theck if there is a line with 7 board that need to be cleard
bool Bricks::FullLinecheck(pos p)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < sides; j++)
		{
			if (LineManager[i][j] == 7)
			{
				clearline(i, j);
				for (int t = i; t < lines-1 ; t++)//"drop the lines above the erased line"
				{
					LineManager[t][j] = LineManager[t + 1][j];
				}
				LineManager[lines-1][j] = 0;
				return true;
			}
		}
	}
	return false;
}
// after pausing the game redrawing the bricks
void Bricks::draw() const
{
	for (auto b : Bklist[left])
	{
		b.draw();
	}
	for (auto b : Bklist[right])
	{
		b.draw();
	}
}

//In according to "Full line check" Clears the line if needed
void Bricks::clearline(int line, int side)
{
	std::list<Board>::iterator it1 = Bklist[side].begin(), it2;
	Bricks::pos pside = (Bricks::pos)side;//for casting
	bool erase = false;
	for (auto b : Bklist[pside])
	{
		if (erase)
		{
			Bklist[pside].erase(it2);
			erase = false;
		}
		it2 = it1;
		if (abs((MAX_X + 1)*side - b.getX()) == line)//check if this is the right brick to erase
		{
			b.erase();
			erase = true;

		}
		it1++;
	}
	if (erase)//if the brick is the last one in the list
	{
		Bklist[pside].erase(it2);
		erase = false;
	}
	for (auto &b : Bklist[pside])
	{
		if (abs((MAX_X + 1)*side - b.getX()) > line)//drop all the other boards that above the cleard line
		{
			b.verticalmove((BoardPos)pside);
		}
	}
}


