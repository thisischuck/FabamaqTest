#include "main.h"
#include "button.h"

int main()
{
	// Initialization
	InitWindow(SCR_WIDTH, SCR_HEIGHT, "raylib");

	SetTargetFPS(60); // Set our game to run at 60 frames-per-second
	Color c = BLACK;

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		// Update
		Button a = createButton(400, 400, 50, 70);
		Vector2 mouse = GetMousePosition();

		buttonUpdate(&a, mouse);

		if (a.activate)
		{
			c = BLUE;
		}

		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		buttonDraw(a, c);

		DrawText(TextFormat("%f, %f", mouse.x, mouse.y), 10, 20, 20, BLACK);

		DrawFPS(0, 0);

		EndDrawing();
	}

	// De-Initialization
	CloseWindow(); // Close window and OpenGL context
	return SUCCESS;
}