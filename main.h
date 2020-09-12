#ifndef _MAIN_
#define _MAIN_

#include "raylib.h"

#define SCR_WIDTH 800
#define SCR_HEIGHT 600
#define MAIN_FONT_SIZE 10

#define FAIL -1
#define SUCCESS 0

typedef struct game
{
	int credits;
	int state; //0 start, 1 Playing, 2 Paused
	int playNumber;
	bool playing;
} Game;

#endif