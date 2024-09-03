#pragma once
#include <raylib.h>
#include <vector>
class Circle
{
public:
	Circle(Vector2 Center, float radius);
	~Circle();
	std::vector <Vector2> CirclePoints;
	std::vector <Vector2> CirclePoints2;
	void DrawCircle(std::vector <Vector2> points1, std::vector <Vector2> points2);
};

