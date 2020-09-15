#include "game.h"
#include "stdlib.h"

Game createGame()
{
	Game g = {0, 0, 0, 0, 0, false};
	return g;
}

int resetTarget(Target *target)
{
	target->position.y = 0;
	target->speed = 5;
	target->stopped = false;
	return 0;
}

Target createTarget(int index)
{
	Color color = {GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255};
	float x = 160 + index * (SCR_WIDTH - 155) / 50;
	Vector2 position = {x, 0.0f};
	//float speed = GetRandomValue(1, 5);
	//int weight = GetRandomValue(3, 10);
	int speed = 5;
	int weight = 5;
	return (Target){10, weight, speed, position, color, false};
}

int gameUpdateOne(int state, Target *target)
{
	//If it's not playing. Don't Update
	if (state != 1 || target->stopped == true)
		return 0;

	//Update Everything
	int radius = target->radius;
	float x = target->position.x;
	float y = target->position.y;
	float xspeed = target->speed;
	float yspeed = target->speed;

	//x += xspeed;
	yspeed += target->weight * GetFrameTime();
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
		yspeed *= -0.8;

		float tmp = abs(yspeed);
		if (tmp <= 0.05f)
			target->stopped = true;
	}
	else if (y - radius < 0)
	{
		y = radius;
		yspeed *= -0.8;
	}

	//Giving it back
	target->speed = yspeed;
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
		float y = -TITLE_FONT_SIZE / 2 + SCR_HEIGHT / 2;
		DrawText("PAUSED", x, y, TITLE_FONT_SIZE, BLACK);
	}

	return 0;
}

bool gameEndOne(Target *target)
{
	return target->stopped;
}

bool gameEnd(Target targets[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!gameEndOne(&targets[i]))
			return false;
	}
	return true;
}