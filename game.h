#ifndef _GAME_
#define _GAME_

#include "main.h"

Game createGame();

Target createTarget(int index);
int resetTarget(Target *target);
int gameUpdateOne(int state, Target *target);
int gameDrawOne(int state, Target *target);
int gameDrawPause(int state);
bool gameEndOne(Target *target);
bool gameEnd(Target targets[], int size);

#endif