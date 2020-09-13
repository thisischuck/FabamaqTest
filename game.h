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

typedef struct target
{
	int radius;
	Vector2 speed;
	Vector2 position;
	Color color;
} Target;

Game createGame();

Target createTarget();
int gameUpdateOne(int state, Target *target);
int gameDrawOne(int state, Target *target);
int gameDrawPause(int state);
bool gameEnd();

#endif