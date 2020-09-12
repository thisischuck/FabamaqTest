#ifndef _GAME_
#define _GAME_

#include "main.h"

typedef struct game
{
	int credits;
	int state; //0 start, 1 Playing, 2 Paused
	int playNumber;
	bool playing;
} Game;

Game createGame();

int gameInitialize();
int gameUpdate(int state);
int gameDraw(int state);
bool gameEnd();

#endif