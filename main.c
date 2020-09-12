#include "main.h"
#include "button.h"

int main()
{
	// Initialization
	InitWindow(SCR_WIDTH, SCR_HEIGHT, "raylib");
	SetTargetFPS(60); // Set our game to run at 60 frames-per-second

	Color c = BLACK;
	Game g = {0, 0, 0, false};

	Button start = createButton(10, 50, 100, 50, BLUE, "START");
	Button creditsIn = createButton(10, 100, 100, 50, GREEN, "CREDITS IN");
	Button creditsOut = createButton(10, 150, 100, 50, MAROON, "CREDITS OUT");

	Button *buttons[] = {&start, &creditsIn, &creditsOut};
	int buttonsSize = 3;

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		// Update
		Vector2 mouse = GetMousePosition();

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

		// Draw
		BeginDrawing();
		DrawRectangle(0, 0, 150, 600, LIGHTGRAY);
		DrawRectangle(150, 0, 5, 600, BLACK);
		for (int i = 0; i < buttonsSize; i++)
		{
			buttonDraw(buttons[i]);
		}
		ClearBackground(RAYWHITE);
		DrawText(TextFormat("%i", g.credits), 10, 500, 10, BLACK);
		DrawText(TextFormat("%i", g.state), 0, 0, 10, BLACK);
		EndDrawing();
	}

	// De-Initialization
	CloseWindow(); // Close window and OpenGL context
	return SUCCESS;
}