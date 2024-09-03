#include <raylib.h>
#include "Button.h"
#include "Circle.h"

int main() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(90);
	int width = 200, length = 200;
	InitWindow(1280, 720, "Questionary");
	Color col = BLUE;
	Button but(100, 100, 200, 200, col, "ABEME");

	Vector2 vecEmm;
	vecEmm.x = 400;
	vecEmm.y = 400;

	Circle mycirle(vecEmm, 200);
	int iii = 0;
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		but.rect.x = mycirle.CirclePoints[iii].x;
		but.rect.y = mycirle.CirclePoints2[iii].y;
		iii++;
		if (iii == mycirle.CirclePoints.size() - 1) {
			iii = 0;
		}
		but.DrawButton1();
		mycirle.DrawCircle(mycirle.CirclePoints, mycirle.CirclePoints2);
		if (but.IsClicked()) {
			but.ButtonColor = RED;
		}
		but.IsCrossed();

		EndDrawing();
	}
	
	CloseWindow();
}