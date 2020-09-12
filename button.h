#include "main.h"

#ifndef _buttonH_
#define _buttonH_

typedef struct button
{
	Rectangle rec;
	Color c;
	int state; // 0 normal, 1 pressed, 2 hover
	bool activate;
	char text[20];
} Button;

int buttonDraw(Button *a);
Button createButton(int x, int y, int width, int height, Color c, char text[]);
bool mouseOnButton(Vector2 mousePosition, Button *b);
int buttonUpdate(Button *b, Vector2 mousePosition);

#endif