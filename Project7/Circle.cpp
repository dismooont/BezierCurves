#include "Circle.h"

Circle::Circle(Vector2 Center, float radius)
{
    int x0 = Center.x;
    int y0 = Center.y;

    for (int x = x0 - radius; x <= x0 + radius; x++)
    {
        int y = sqrt(radius * radius - (x - x0) * (x - x0)) + y0;
        Vector2 point;
        point.x = x;
        point.y = y;
        CirclePoints.push_back(point);

        y = -sqrt(radius * radius - (x - x0) * (x - x0)) + y0;
        Vector2 point2;
        point2.x = x;
        point2.y = y;
        CirclePoints2.push_back(point2);

    }

}

Circle::~Circle()
{
}

void Circle::DrawCircle(std::vector<Vector2> points1, std::vector<Vector2> points2)
{
    for (int i = 0; i < points1.size(); i++) {
        DrawPixel(points1[i].x, points1[i].y,BLACK);
    }
    for (int i = 0; i < points2.size(); i++) {
        DrawPixel(points2[i].x, points2[i].y, BLACK);
    }
}

