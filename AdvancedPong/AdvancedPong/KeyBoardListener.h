#pragma once
class Board;
class Ball;
class Bricks;
enum class Mode;
//abstract class the will enharit key board event functions
class KeyBoardListener
{
public:
	virtual void handleKey(char k, bool &continuegame, bool &newgame, const Board *L, const Board *R, Ball &b, const Bricks &brickmanager, difficult & d, Mode & GameMode) = 0;
	virtual const char* getKbChars() = 0;
};