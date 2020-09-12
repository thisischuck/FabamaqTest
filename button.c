#include "button.h"

//Creates a button
Button createButton(int x, int y, int width, int height)
{
	Button btn;
	btn.state = 0;
	btn.activate = false;
	Rectangle r = {x, y, width, height};
	btn.rec = r;
	return btn;
}

//Called to draw buttons
int buttonDraw(Button a, Color c)
{
	DrawRectangle(a.rec.x, a.rec.y, a.rec.width, a.rec.height, c);
	return 0;
}

//Basicaly Just a rename for code clarity also changes the button state
bool mouseOnButton(Vector2 mousePosition, Button *b)
{
	return CheckCollisionPointRec(mousePosition, b->rec);
}

int buttonUpdate(Button *b, Vector2 mousePosition)
{
	b->activate = false;

	if (mouseOnButton(mousePosition, b))
	{
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
			b->state = 1;
		else
			b->state = 2;

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			b->activate = true;
	}
	else
		b->state = 0;
}