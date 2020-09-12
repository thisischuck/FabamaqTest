#include "main.h"

#ifndef _buttonH_
#define _buttonH_

typedef struct button
{
	Rectangle rec;
	int state; // 0 normal, 1 pressed, 2 hover
	bool activate;
} Button;

int buttonDraw(Button a, Color c);
Button createButton(int x, int y, int width, int height);
bool mouseOnButton(Vector2 mousePosition, Button *b);
int buttonUpdate(Button *b, Vector2 mousePosition);

#endif