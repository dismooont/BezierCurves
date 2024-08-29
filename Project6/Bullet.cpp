#include "Bullet.h"


Bullet::Bullet(Texture2D texture, float xAimPoint, float yAimPoint)
{
	bulletTexture = texture;
	for (float i = 0; i <= 100; i++) {
		float i2 = i/100 * i/100;
		float i3 = i2 * i/100;

		float b0 = 1 - 3 * i/100 + 3 * i2 - i3;
		float b1 = 3 * i/100 - 6 * i2 + 3 * i3;
		float b2 = 3 * i2 - 3 * i3;
		float b3 = i3;

		Vector2 vec2;
		vec2.x = b0 * 700 + b1 * 500 + b2 * 400 + b3 * 100;
		vec2.y = b0 * 500 + b1 * 100 + b2 * 100 + b3 * 500;


		MoveArray.push_back(vec2);

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
