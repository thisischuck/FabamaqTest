#include "game.h"

Game createGame()
{
	Game g = {0, 0, 0, false};
	return g;
}

Target createTarget()
{
	Color color = {GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255};
	Vector2 speed = {GetRandomValue(1, 5), GetRandomValue(1, 5)};
	Vector2 position = {GetRandomValue(155, SCR_WIDTH), GetRandomValue(0, SCR_HEIGHT)};
	return (Target){10, speed, position, color};
}

int gameUpdateOne(int state, Target *target)
{
	//If it's not playing. Don't Update
	if (state != 1)
		return 0;

	//Update Everything
	int radius = target->radius;
	int x = target->position.x;
	int y = target->position.y;
	int xspeed = target->speed.x;
	int yspeed = target->speed.y;
	x += xspeed;
	y += yspeed;
	//Collisions
	if (x + radius > SCR_WIDTH)
	{
		x = SCR_WIDTH - radius;
		xspeed *= -1;
	}
	else if (x - radius < GAMEBOUNDS.x)
	{
		x = GAMEBOUNDS.x + radius;
		xspeed *= -1;
	}

	if (y + radius > SCR_HEIGHT)
	{
		y = SCR_HEIGHT - radius;
		yspeed *= -1;
	}
	else if (y - radius < 0)
	{
		y = radius;
		yspeed *= -1;
	}

	//Giving it back
	target->speed = (Vector2){xspeed, yspeed};
	target->position = (Vector2){x, y};

	return 1;
}

int gameDrawOne(int state, Target *target)
{
	//If it's on the start don't draw.
	//Needs to draw while paused
	if (state == 0)
		return 1;

	DrawCircle(target->position.x, target->position.y, target->radius, target->color);

	return 0;
}

int gameDrawPause(int state)
{
	//Only draws when paused
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