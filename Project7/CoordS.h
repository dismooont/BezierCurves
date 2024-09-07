#pragma once
#include <vector>
#include <raylib.h>
class CoordS
{
public:
	CoordS(int XLen, int YLen, int XSize, int YSize);
	~CoordS();
	void ShowFunc(std::vector <Vector2> pointArray);
	void ShowCoordS();
	int X , Y ,XSize1, YSize1;
	Rectangle rect;
};

