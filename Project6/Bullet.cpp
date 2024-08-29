#include "Bullet.h"


Bullet::Bullet(Texture2D texture, float xAimPoint, float yAimPoint)
{
	bulletTexture = texture;
	for (int i = 100; i > 0; i--) {
		Vector2 vec2;
		vec2.x = xAimPoint;
		vec2.y = yAimPoint;
		MoveArray.push_back(vec2);
		xAimPoint-=4;
		yAimPoint-=2;
	}
}

Bullet::~Bullet()
{
	
}

int Bullet::Move(std::vector<Vector2> MoveVec)
{
	if (MoveCounter < MoveArray.size()) {
		DrawTexture(bulletTexture, MoveArray[MoveCounter].x, MoveArray[MoveCounter].y, WHITE);
		MoveCounter++;
	}
	else {
		Bullet:: ~Bullet();
	}
	return 0;
}
