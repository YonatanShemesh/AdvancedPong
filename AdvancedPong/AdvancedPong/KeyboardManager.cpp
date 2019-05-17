#include <conio.h>
#include "KeyboardManager.h"

//register  keyboard listener for the boards
//register  keyboard listener for the game

void KeyboardManager::registerKbListener(KeyBoardListener* KbListener)
{
	int index;
	const char * chars = KbListener->getKbChars();
	size_t numCharToRegister = strlen(chars);
	for (size_t i = 0; i < numCharToRegister; ++i)
	{
		if (chars[i] == 27)
			index = 26;
		else
			index = getIndex(chars[i]);
		if (index != -1)
		{
			kbListeners[index].push_back(KbListener);
		}
	}
}

//check if there was any keyboard hit and send it to all the registered relevant listeners
void KeyboardManager::handleKeyboard(bool &c, bool &n, const Board *L, const Board *R, Ball &b,const Bricks &brick,difficult & d, Mode & GameMode)
{
	if (_kbhit())
	{
		int index;
		char k = tolower(_getch());
		if (k == 27)
			index = 26;
		else
			index = getIndex(k);
		if (index != -1)
		{
			for (auto pKbListener : kbListeners[index])
			{
				pKbListener->handleKey(k, c, n, L, R,b,brick,d,GameMode);
			}
		}
	}
}
