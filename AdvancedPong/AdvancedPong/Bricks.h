#pragma once
#include "Board.h"
#include <list>
#include <iostream>
#include"utils.h"

enum { lines = 21, sides = 2 };
class Bricks
{
protected:
	//screen borders
	enum { MAX_Y = 24, MIN_Y = 4, MAX_X = 79, MIN_X = 1 };
	//bricks "Grave yard" borders
	//holds all of the bricks that died
	std::list<Board> Bklist[sides];
	//follow the capacity of each line
	// when a miss is declear it Adds the Paddle that missed to the "grave yard"
	void Addbrick(Board brick)
	{
		Bklist[(int)brick.getpos()].push_back(brick);
		LineManager[abs((MAX_X + 1)*(int)brick.getpos() - brick.getX())][(int)brick.getpos()]++;
	}
	// When completing a full line
	friend class Board;
	friend class Ball;

public:
	int LineManager[lines][sides] = {};
	void clearline(int line, int side);
	//left or right tetris
	enum pos { left, right };
	//Dtor to free the list
	~Bricks()
	{
		Bklist->empty();
	}
	void Fall(Board brick);
	bool FullLinecheck(pos p);
	void draw()const;
};