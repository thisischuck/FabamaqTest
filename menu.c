#include "menu.h"
#include "button.h"
#

int centerPosition(Rectangle bounds, int fontSize, char *text)
{
	int textSize = MeasureText(text, fontSize);
	return -textSize / 2 + bounds.width / 2;
}

int drawMenu(Game *g, Button *buttons[], int buttonsSize)
{
	DrawRectangle(0, 0, 150, 600, LIGHTGRAY);
	DrawRectangle(150, 0, 5, 600, BLACK); //Divider
	for (int i = 0; i < buttonsSize; i++)
	{
		buttonDraw(buttons[i]);
	}

	Rectangle bounds = {0, 0, 150, 600};
	char c[20] = "INFO";
	//INFO
	DrawText(c, centerPosition(bounds, MENU_FONT_SIZE, c), 320, MENU_FONT_SIZE, BLACK);

	TextCopy(c, "BUTTONS");
	DrawText(c, centerPosition(bounds, MENU_FONT_SIZE, c), 20, MENU_FONT_SIZE, BLACK);
	//CREDITS
	TextCopy(c, "CREDITS:");
	DrawText(c, centerPosition(bounds, 18, c), 400, 18, BLACK);
	TextCopy(c, TextFormat("%i", g->credits));
	DrawText(c, centerPosition(bounds, 18, c), 420, 18, BLACK);
	//Num PLAYS
	TextCopy(c, "N PLAYS:");
	DrawText(c, centerPosition(bounds, 18, c), 440, 18, BLACK);
	TextCopy(c, TextFormat("%i", g->playNumber));
	DrawText(c, centerPosition(bounds, 18, c), 460, 18, BLACK);
	//CREDITS IN
	TextCopy(c, "CREDITS IN:");
	DrawText(c, centerPosition(bounds, 18, c), 480, 18, BLACK);
	TextCopy(c, TextFormat("%i", g->creditsIn));
	DrawText(c, centerPosition(bounds, 18, c), 500, 18, BLACK);
	//CREDITS OUT
	TextCopy(c, "CREDITS OUT:");
	DrawText(c, centerPosition(bounds, 18, c), 520, 18, BLACK);
	TextCopy(c, TextFormat("%i", g->creditsOut));
	DrawText(c, centerPosition(bounds, 18, c), 540, 18, BLACK);

	return 0;
}