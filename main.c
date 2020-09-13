#include "main.h"
#include "button.h"
#include "game.h"

int main()
{
	// Initialization //////////////////////////////////////////////
	InitWindow(SCR_WIDTH, SCR_HEIGHT, "raylib");
	SetTargetFPS(60); // Runs at 60 fps

	Game g = createGame();

	Button start = createButton(10, 50, 100, 50, BLUE, "START");
	Button creditsIn = createButton(10, 100, 100, 50, GREEN, "CREDITS IN");
	Button creditsOut = createButton(10, 150, 100, 50, MAROON, "CREDITS OUT");
	Button *buttons[] = {&start, &creditsIn, &creditsOut};
	int buttonsSize = 3;
	int maxSize = 50;
	int currentSize = 0;
	int timer = 0;
	int timerSize = 15;

	Target targets[50];
	for (int i = 0; i < 50; i++)
	{
		targets[i] = createTarget(i);
	}

	// Main Loop
	while (!WindowShouldClose()) // Window close or ESC
	{
		// Update //////////////////////////////////////////////////
		Vector2 mouse = GetMousePosition();

		//ButtonLogic
		for (int i = 0; i < buttonsSize; i++)
		{
			buttonUpdate(buttons[i], mouse);
		}
		if (start.activate)
		{
			switch (g.state)
			{
			case 0:
				if (g.credits > 0)
				{
					g.state = 1;
					g.credits--;
				}
				break;
			case 1:
				g.state = 2;
				break;
			case 2:
				g.state = 1;
				break;
			}
		}
		if (creditsIn.activate)
			g.credits++;
		if (creditsOut.activate && g.credits > 0)
			g.credits--;

		//GameLogic

		//Interval Logic
		if (g.state == 1 && currentSize < maxSize)
		{
			timer += 1;
			if (timer >= timerSize)
			{
				currentSize++;
				timer = 0.0f;
			}
		}
		//Update In order, with an interval
		for (int i = 0; i < currentSize; i++)
		{
			gameUpdateOne(g.state, &targets[i]);
		}

		//Check for game end
		if (gameEnd(targets, maxSize))
		{
			g.state = 0;
			g.playNumber++;
			currentSize = 0;
			timer = 0;
			for (int i = 0; i < maxSize; i++)
			{
				resetTarget(&targets[i]);
			}
		}

		// Draw ////////////////////////////////////////////////////
		BeginDrawing();
		ClearBackground(RAYWHITE);
		//Menu
		DrawRectangle(0, 0, 150, 600, LIGHTGRAY);
		DrawRectangle(150, 0, 5, 600, BLACK);
		for (int i = 0; i < buttonsSize; i++)
		{
			buttonDraw(buttons[i]);
		}
		DrawText(TextFormat("%i", g.credits), 10, 500, 10, BLACK);
		//Game
		for (int i = 0; i < currentSize; i++)
		{
			gameDrawOne(g.state, &targets[i]);
		}
		gameDrawPause(g.state);

		//DEBUG DRAWS
		DrawText(TextFormat("%i", g.state), 0, 0, 20, BLACK);
		//DrawLine(75 + SCR_WIDTH / 2, 0, 75 + SCR_WIDTH / 2, SCR_HEIGHT, PINK);
		//DrawLine(0, SCR_HEIGHT / 2, SCR_WIDTH, SCR_HEIGHT / 2, PINK);
		EndDrawing();
	}

	// De-Initialization
	CloseWindow(); // Close window and OpenGL context
	return SUCCESS;
}