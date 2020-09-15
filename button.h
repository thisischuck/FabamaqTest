#include "main.h"

#ifndef _BUTTON_
#define _BUTTON_

int buttonDraw(Button *a);
Button createButton(int x, int y, int width, int height, Color c, char text[]);
bool mouseOnButton(Vector2 mousePosition, Button *b);
int buttonUpdate(Button *b, Vector2 mousePosition);

#endif