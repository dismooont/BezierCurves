#include "CoordS.h"

CoordS::CoordS(int XLen, int YLen, int XSize, int YSize)
{
	X = XLen;
	Y = YLen;
	XSize1 = XSize;
	YSize1 = YSize;
	rect.x = X;
	rect.y = Y;
	rect.width = XSize;
	rect.height = YSize;
}

void CoordS::ShowCoordS()
{
	DrawRectangleLines(X, Y, XSize1, YSize1, BLACK);
	for (int i = 20; i < XSize1; i += 20) {
		DrawLine(X + i, Y, X + i,Y + YSize1, BLUE);
	}
	for (int i = 0; i < YSize1; i += 20) {
		DrawLine(X, Y + i, X + XSize1, Y + i, BLUE);
	}
}
CoordS::~CoordS() {

}
