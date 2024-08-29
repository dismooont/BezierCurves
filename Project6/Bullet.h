#pragma once
#include <raylib.h>
#include <vector>

class Bullet
{
public:
	Bullet(Texture2D texture, float xAimPoint, float yAimPoint);
	~Bullet();
	int Move(std::vector <Vector2> MoveVec);
	std::vector <Vector2> MoveArray;
	int MoveCounter=0;
private:
	Texture2D bulletTexture;

};

