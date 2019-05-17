#include "Game.h"
unsigned long long int game_iteration = 0;
unsigned long long int bomb_game_step = 0;
int life_left = 16, life_right = 16;
//launching the game from the main
bool Game::Launch(difficult &dif, Mode & game_mode)
{
	int choise;
	while (true)
	{
		s.ClearScreen();
		s.launch();
		do
		{
			choise = _getch();
			if (choise == Present)
			{
				s.present();
				_getch();//wait for hit and clear the buffer
			}
			if (choise == Starthh)
			{
				game_mode = Mode::H_H;
				return true;
			}
			if (choise == Starthc)
			{
				game_mode = Mode::H_C;
				dif = chosedifficult();
				return true;
			}
			if (choise == Startcc)
			{
				game_mode = Mode::C_C;
				dif = chosedifficult();
				return true;
			}
			if (choise == EXIT)
				return false;

		} while (choise != Present && choise != Starthh && choise != Starthc && choise != Startcc && choise != EXIT);
	}
}

int Game::pause()
{
	int choise;
	s.ClearScreen();
	s.start();
	choise = _getch();
	return choise;
}

//genetares all the game participants and Starts a new Game Loop 
bool Game::start(difficult & d, Mode & GameMode)
{
	Game g;
	Board *players[4],*Lplayer,*Rplayer;
	UserBoard UserLBoard({ 4,10,'#' }, { 4,12,'#' }, BoardPos::left, "qas"), UserRBoard({ 76,11,'#' }, { 76,13,'#' }, BoardPos::right, "plk");
	PcBoard PcLBoard({ 4,10,'#' }, { 4,12,'#' }, BoardPos::left,d), PcRBoard({ 76,11,'#' }, { 76,13,'#' }, BoardPos::right,d);
	Board *Who_missed;
	players[0] = &UserLBoard;
	players[1] = &UserRBoard;
	players[2] = &PcLBoard;
	players[3] = &PcRBoard;
	Ball ball({ 40,12,'O' }, { 43,12,'O' });
	KeyboardManager kbManager;
	switch(GameMode)
	{
	default:
		Lplayer = players[0];
		Rplayer = players[1];
		break;
	case(Mode::H_H):
		Lplayer = players[0];
		Rplayer = players[1];
		kbManager.registerKbListener(dynamic_cast<UserBoard*>(Lplayer));
		kbManager.registerKbListener(dynamic_cast<UserBoard*>(Rplayer));
		break;
	case(Mode::H_C):
		Lplayer = players[0];
		Rplayer = players[3];
		kbManager.registerKbListener(dynamic_cast<UserBoard*>(Lplayer));
		break;
	case(Mode::C_C):
		Lplayer = players[2];
		Rplayer = players[3];
		break;
	}
	Bricks brickmanager;
	bool continuegame = true, newgame = false;
	s.ClearScreen();
	Lplayer->draw();
	Rplayer->draw();
	kbManager.registerKbListener(&g);
	s.MakeLayout();
	s.drawLifes(Lplayer, Rplayer);
	ball.draw();
	bool missed = false,bigmissed=false,goodmissed = false;
	while (continuegame)
	{
		hideConsoleCursor();
		//gives the player advantage on the ball
		for (int i = 0; i < 1; i++)
		{
			kbManager.handleKeyboard(continuegame, newgame, Lplayer, Rplayer,ball, brickmanager,d,GameMode);
			Lplayer->move(ball);
			Rplayer->move(ball);
			Sleep(50);
		}

		if (continuegame)
		{
			//find out if a player missed the ball and who's the player that missed
			Who_missed = checkMissed(Lplayer, Rplayer, ball, missed,bigmissed,goodmissed,brickmanager);
			//if there was a miss
			if (missed)
			{

				g.disqualification(brickmanager, (Who_missed->getX() == Rplayer->getX() ? Rplayer : Lplayer), ball,bigmissed,goodmissed);
				s.drawLifes(Lplayer, Rplayer);
				continuegame = g.gameover(*Lplayer) && g.gameover(*Rplayer);
				//when there was a miss and the game havent over
				if (continuegame)
				{
					ball.reset();
					missed = false;
					bigmissed = false;
					goodmissed = false;
				}
				//there was a game over
				else
				{
					s.ClearScreen();
					s.gameover();
				}

			}
			//pc player bomb story 
			if (GameMode == Mode::H_C)
				((PcBoard*)Rplayer)->activate(ball,*Lplayer);
			//pc player bomb story 
			if (GameMode == Mode::C_C)
			{
				((PcBoard*)Rplayer)->activate(ball, *Lplayer);
				((PcBoard*)Lplayer)->activate(ball, *Rplayer);
			}



			count_game_iteration(ball);
			ball.move();
			//change state according to game iterations.
			if (ball.getstate() == ball.getbecome() || ball.getstate() == ball.getbomb())
			{
				bomb_game_step++;
				if (bomb_game_step == 8)
					ball.getstate()->NextState();
				if (bomb_game_step >= 12&&ball.get_X_left()>=Lplayer->getX()&& ball.get_X_right() <= Rplayer->getX())
				{
					ball.getstate()->NextState();
					bomb_game_step = 0;
				}
			}
		}
	}
	return newgame;
}


//checkes the ball position and reactes to the states ("Missed, center hit, corner hit, Away")
Board* Game::checkMissed(Board *Lplayer, Board *Rplayer, Ball& ball, bool & missed, bool & bigmissed, bool & goodmissed,Bricks &bricks)
{
	int line;
	Board temp[1];
	BallPosition stateLeft = Lplayer->checkBallPosition(ball);
	BallPosition stateRihgt = Rplayer->checkBallPosition(ball);
	//================================================
	//checks the staus of the left board player
	switch (stateLeft)
	{
	case BallPosition::AWAY:
		break;
	case BallPosition::MISSED_REG:
	{
		missed = true;
		return Lplayer;
	}
	case BallPosition::MISSED_BE:
		if (ball.get_X_left() == Screen::MIN_X || ball.checkforbricks(&bricks, *Lplayer, line))
		{
			missed = true;
			bomb_game_step = 0;
			return Lplayer;
		}
		else
			missed = false;
		break;
	case BallPosition::MISSED_BOMB:
		if (ball.checkforbricks(&bricks, *Lplayer, line))
		{
			missed = true;
			goodmissed = true;
			bricks.clearline(line, (int)Lplayer->getpos());
			for (int t = line; t < lines - 1; t++)//"drop the lines above the erased line"
			{
				bricks.LineManager[t][(int)Lplayer->getpos()] = bricks.LineManager[t + 1][(int)Lplayer->getpos()];
			}
			bricks.LineManager[lines - 1][(int)Lplayer->getpos()] = 0;
			bomb_game_step = 0;
			return Lplayer;
		}
		else if (ball.get_X_left() == Screen::MIN_X)
		{
			line = 1;
			missed = true;
			goodmissed = true;
			bricks.clearline(line, (int)Lplayer->getpos());
			for (int t = line; t < lines - 1; t++)//"drop the lines above the erased line"
			{
				bricks.LineManager[t][(int)Lplayer->getpos()] = bricks.LineManager[t + 1][(int)Lplayer->getpos()];
			}
			bricks.LineManager[lines - 1][(int)Lplayer->getpos()] = 0;
			bomb_game_step = 0;
			return Lplayer;
		}
		else
			missed = false;
		break;
	case BallPosition::CORNER_HIT:
		ball.changeYDirection(); // no break intentionally - change also the X dir!!!
		//ball.changeXDirection();
		//break;
	case BallPosition::CENTER_HIT:
		if (ball.getY() - 3 >= Screen::MIN_Y && ball.getY() + 3 <= Screen::MAX_Y && (ball.get_X_left() - Lplayer->getX()) != 0)
			ball.animate_left(ball.getYDirection());
		ball.changeXDirection();
		break;
	case BallPosition::CORNER_HIT_BE:
		ball.setstate(ball.getregular());
		ball.changeYDirection(); // no break intentionally - change also the X dir!!!
		//ball.changeXDirection();
		//break;
		break;
	case BallPosition::CENTER_HIT_BE:
		ball.setstate(ball.getregular());
		if (ball.getY() - 3 >= Screen::MIN_Y && ball.getY() + 3 <= Screen::MAX_Y && (ball.get_X_left() - Lplayer->getX()) != 0)
			ball.animate_left(ball.getYDirection());
		ball.changeXDirection();
		break;
	case BallPosition::BOMB_HIT:
		missed = true;
		bigmissed = true;
		ball.getstate()->NextState();
		bomb_game_step = 0;
		return Lplayer;
		break;
	}
	//checks the staus of the left board player
	switch (stateRihgt)
	{
	case BallPosition::AWAY:
		break;
	case BallPosition::MISSED_REG:
	{
		missed = true;
		return Rplayer;
	}
	case BallPosition::MISSED_BE:
		if (ball.get_X_right() == Screen::MAX_X || ball.checkforbricks(&bricks, *Rplayer, line))
		{
			missed = true;
			bomb_game_step = 0;
			return Rplayer;
		}
		else
			missed = false;
		break;
	case BallPosition::MISSED_BOMB:
		if (ball.checkforbricks(&bricks, *Rplayer, line))
		{
			missed = true;
			goodmissed = true;
			bricks.clearline(line, (int)Rplayer->getpos());
			for (int t = line; t < lines - 1; t++)//"drop the lines above the erased line"
			{
				bricks.LineManager[t][(int)Rplayer->getpos()] = bricks.LineManager[t + 1][(int)Rplayer->getpos()];
			}
			bricks.LineManager[lines - 1][(int)Rplayer->getpos()] = 0;
			bomb_game_step = 0;
			return Rplayer;
		}
		else if (ball.get_X_right() == Screen::MAX_X)
		{
			line = 1;
			missed = true;
			goodmissed = true;
			bricks.clearline(line, (int)Rplayer->getpos());
			for (int t = line; t < lines - 1; t++)//"drop the lines above the erased line"
			{
				bricks.LineManager[t][(int)Rplayer->getpos()] = bricks.LineManager[t + 1][(int)Rplayer->getpos()];
			}
			bricks.LineManager[lines - 1][(int)Rplayer->getpos()] = 0;
			bomb_game_step = 0;
			return Rplayer;
		}
		else
			missed = false;
		break;
	case BallPosition::CORNER_HIT:
		ball.changeYDirection(); // no break intentionally - change also the X dir!!!
		//ball.changeXDirection();
		//break;
	case BallPosition::CENTER_HIT:
		if (ball.getY() - 3 >= Screen::MIN_Y && ball.getY() + 3 <= Screen::MAX_Y && (ball.get_X_left() - Lplayer->getX()) != 0)
			ball.animate_left(ball.getYDirection());
		ball.changeXDirection();
		break;
	case BallPosition::CORNER_HIT_BE:
		ball.setstate(ball.getregular());
		ball.changeYDirection(); // no break intentionally - change also the X dir!!!
		//ball.changeXDirection();
		//break;
		break;
	case BallPosition::CENTER_HIT_BE:
		ball.setstate(ball.getregular());
		if (ball.getY() - 3 >= Screen::MIN_Y && ball.getY() + 3 <= Screen::MAX_Y && (ball.get_X_left() - Lplayer->getX()) != 0)
			ball.animate_left(ball.getYDirection());
		ball.changeXDirection();
		break;
	case BallPosition::BOMB_HIT:
		missed = true;
		bigmissed = true;
		ball.getstate()->NextState();
		bomb_game_step = 0;
		return Rplayer;
		break;
	}
	return temp;
}

// Handle the key Board hit of Escape
void Game::handleKey(char c, bool &continuegame, bool &newgame, const Board *L, const Board *R, Ball &b,const Bricks &brickmanager, difficult & d, Mode & GameMode)
{
	if (c == characters[Escape])
	{
		int choise;
		while (true)
		{
			choise = pause();
			switch (choise)//keys for the manu
			{
			default:
				std::cout << "wrong choise";
				break;
			case Starthh:
				GameMode = Mode::H_H;
				newgame = true;
				continuegame = false;
				return;
			case Starthc:
				GameMode = Mode::H_C;
				d = chosedifficult();
				newgame = true;
				continuegame = false;
				return;
			case Startcc:
				GameMode = Mode::C_C;
				d = chosedifficult();
				newgame = true;
				continuegame = false;
				return;
			case Continuegame:
				newgame = false;
				continuegame = true;
				s.Redrawgame(L, R, b, brickmanager);
				return;
			case Present:
				s.present();
				_getch();
				break;
			case EXIT:
				newgame = false;
				continuegame = false;
				return;
			}
		}
	}
}

//when a player has missed the ball
void Game::disqualification(Bricks & brick, Board *board, Ball &ball, bool bigmissed, bool & goodmissed)
{
	bool line;
	ball.erase();
	//animateMiss(board, ball);//animate miss 
	brick.Fall(*board);
	board->draw();
	line = brick.FullLinecheck((Bricks::pos)board->getpos());
	if (!line)
		//loses 3 lifes 
		if (bigmissed)
		{
			for (int i = 0; i < 3; i++)
				board->verticalmove((BoardPos)(((int)board->getpos() + 1) % 2));
			board->setlife(-3);
		}
	//regain a life 
		else if (goodmissed)
		{
			board->verticalmove(board->getpos());
			board->setlife(1);
		}
	//regular miss
		else
		{
			board->verticalmove((BoardPos)(((int)board->getpos() + 1) % 2));
			board->setlife(-1);
		}
	//regain 5 lifes 
	else
	{
		for (int i = 0; i < 5; i++)
			board->verticalmove(board->getpos());
		board->setlife(5);
	}
}

bool Game::gameover(Board b)
{
	return (!((b.getX() >= 20&& b.getX() <= 40) || (b.getX() <= 60&& b.getX() >= 40)));
}







