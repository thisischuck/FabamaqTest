#ifndef _MAIN_
#define _MAIN_

#include "raylib.h"

#define SCR_WIDTH 800
#define SCR_HEIGHT 600
#define MAIN_FONT_SIZE 12
#define MENU_FONT_SIZE 28
#define TITLE_FONT_SIZE 50
#define FAIL -1
#define SUCCESS 0
#define PAUSEDCOLOR \
	(Color) { 0, 0, 0, 100 }
#define GAMEBOUNDS \
	(Rectangle) { 155, 0, SCR_WIDTH - 155, SCR_HEIGHT }

typedef struct game
{
	int credits;
	int state; //0 start, 1 Playing, 2 Paused
	int playNumber;
	int creditsOut;
	int creditsIn;
	bool playing;
} Game;

typedef struct target
{
	int radius;
	int weight;
	float speed;
	Vector2 position;
	Color color;
	bool stopped;
} Target;

typedef struct button
{
	Rectangle rec;
	Color c;
	int state; // 0 normal, 1 pressed, 2 hover
	bool activate;
	char text[20];
} Button;

#endif