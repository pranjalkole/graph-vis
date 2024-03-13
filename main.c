#include "raylib.h"
#include "raymath.h"

//#include <stdio.h>
//#include <stdlib.h>
#include <math.h>

void DrawNode(int i, int x, int y) {
	char text[2] = { i+48, 0 };
	DrawCircleLines(x, y, 1.0, (Color){255, 0, 0, 255});
	DrawCircleLines(x, y, 20.0, (Color){255, 0, 0, 255});
	DrawText(text, x-5, y-10, 20, (Color){0, 0, 0, 255});
}

int main(void) {
	int adj[5][5] = { { 1, 2, 3, -1 }, { 3, 4, -1 }, { 0, 4, -1 }, { 1, 4, -1 }, { 1, 2, 3, -1 } };
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Graph Visualizer");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_LEFT)) {
			// goto prev iter
		}

		if (IsKeyPressed(KEY_RIGHT)) {
			// do next iter of djikstra
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (int i = 0; i < sizeof(adj)/sizeof(adj[0]); i++) {
			DrawNode(i, 500+(100*cos((i*(M_PI*2))/5)), 250+(100*sin((i*(M_PI*2))/5)));
			for (int j = 0; adj[i][j] != -1; j++) {
				DrawLine(500+(100*cos((i*(M_PI*2))/5)), 250+(100*sin((i*(M_PI*2))/5)), 500+(100*cos((j*(M_PI*2))/5)), 250+(100*sin((j*(M_PI*2))/5)), (Color){0,0,0,255});
			}
		}

		DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();
}
