#include "button.h"

//Creates a button
Button createButton(int x, int y, int width, int height, Color c, char text[])
{
	Button btn;
	btn.state = 0;
	btn.activate = false;
	Rectangle r = {x, y, width, height};
	btn.rec = r;
	btn.c = c;
	TextCopy(btn.text, text);
	return btn;
}

//Called to draw buttons
//Draws the button text in the middle of the button
int buttonDraw(Button *a)
{
	Color c = a->c;

	if (a->state == 2)
	{
		c.r += 20;
		c.g += 20;
		c.b += 20;
	}
	else
		c.a = 255;

	DrawRectangle(a->rec.x, a->rec.y, a->rec.width, a->rec.height, c);
	if (TextLength(a->text) > 0)
	{
		int textSize = MeasureText(a->text, MAIN_FONT_SIZE);
		float x = -textSize / 2 + a->rec.x + a->rec.width / 2;
		float y = -MAIN_FONT_SIZE / 2 + a->rec.y + a->rec.height / 2;
		Color c = BLACK;
		if (a->state == 1)
			c = WHITE;
		DrawText(a->text, x, y, MAIN_FONT_SIZE, c);
	}

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

	return 0;
}