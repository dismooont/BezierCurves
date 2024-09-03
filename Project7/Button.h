#pragma once
#include <raylib.h>
class Button
{
public:
	Button(float X, float Y, float sizex, float sizey, Color color,const char* Text);
	~Button();
	void IsCrossed();
	bool IsClicked();
	void DrawButton1();
	int ExtensionCounter=0;
	Rectangle rect;
	Color ButtonColor;
	const char* ButtonText;
};

