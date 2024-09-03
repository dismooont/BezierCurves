#include "Button.h"

Button::Button(float X, float Y, float sizex, float sizey, Color color, const char* Text) {
	rect.height = sizex;
	rect.width = sizey;
	rect.x = X;
	rect.y = Y;
	ButtonColor = color;
	ButtonText = Text;
}
void Button::DrawButton1() {
	DrawRectangleRec(rect, ButtonColor);
	DrawText(ButtonText, rect.x, rect.y, 14, BLACK);
}
Button::~Button() {

}
bool Button::IsClicked() {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && GetMouseX() >= rect.x && GetMouseX() <= rect.width+rect.x && GetMouseY() >= rect.y && GetMouseY() <= rect.height+rect.y) {
		return 1;
	}
	
	return 0;
}
void Button::IsCrossed() {
	Vector2 vec;
	vec.x = GetMouseX();
	vec.y = GetMouseY();
	if (CheckCollisionPointRec(vec, rect) && ExtensionCounter<=5) {
		 
		ExtensionCounter++;
		
		rect.x--;
		rect.width+=2;
		rect.y--;
		rect.height+=2;

	}
	else {
		if (!CheckCollisionPointRec(vec, rect) && ExtensionCounter != 0) {
			ExtensionCounter--;
			rect.x++;
			rect.width -= 2;
			rect.y++;
			rect.height -= 2;

		}
	}
}