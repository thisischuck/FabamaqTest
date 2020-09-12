#include "game.h"

Game createGame()
{
	Game g = {0, 0, 0, false};
	return g;
}

int gameInitialize()
{
	//Define bounding box

	return 0;
}

int gameUpdate(int state)
{
	//If it's not playing. Don't Update
	if (state != 1)
		return 0;

	//Update Everything

	return 1;
}

int gameDraw(int state)
{
	//If it's on the start don't draw.
	//Needs to draw while paused
	if (state == 0)
		return 1;

	//Draw everything

	//DRAWS THE PAUSED SCREEN
	if (state == 2)
	{
		DrawRectangle(155, 0, SCR_WIDTH - 155, SCR_HEIGHT, PAUSEDCOLOR);
		int textSize = MeasureText("PAUSED", TITLE_FONT_SIZE);
		float x = -textSize / 2 + 75 + SCR_WIDTH / 2;
		float y = -TITLE_FONT_SIZE + SCR_HEIGHT / 2;
		DrawText("PAUSED", x, y, TITLE_FONT_SIZE, BLACK);
	}

	return 0;
}

bool gameEnd()
{
	return false;
}