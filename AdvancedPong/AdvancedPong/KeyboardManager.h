#pragma once
#include "utils.h"
#include "Board.h"
#include <list>
#include "Game.h"
#include "KeyBoardListener.h"

class KeyboardManager
{
private:
	enum { NUM_CHARS = 27 };
	std::list<KeyBoardListener*> kbListeners[NUM_CHARS];//Board listerners

	//get the index of the key thats has been hit
	int getIndex(char c)
	{
		int index = c - 'a';
		if (index < 0 || index >= NUM_CHARS) {
			index = c - 'A';
			if (index < 0 || index >= NUM_CHARS) {
				return -1;
			}
		}
		return index;
	}

public:
	void registerKbListener(KeyBoardListener* pKbListener);
	void handleKeyboard(bool &c, bool &n, const Board *L, const Board *R,  Ball &b, const Bricks &brick, difficult & d, Mode & GameMode);

};
