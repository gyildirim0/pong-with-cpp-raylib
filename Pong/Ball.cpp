#include "Ball.h"


Ball::Ball() {

	position.x = 630;
	position.y = 350;
	collision.width = 20;
	collision.height = 20;

	speed = randomSpeed();

}

void Ball::Draw() {

	DrawRectangle(position.x, position.y, 20, 20, WHITE);


}

void Ball::Update() {


	position.x += speed.x;
	position.y -= speed.y;

	collision.x = position.x;
	collision.y = position.y;

	if (position.y <= 0 || position.y >= 700) {
		speed.y *= -1;
	}
	
	
	if (position.x < -50) {
		winner = 1;
		Respawn();
	}
	if (position.x > 1300) {
		winner = -1;
		Respawn();
	}

	




}

void Ball::Respawn() {


	position.x = 630;
	position.y = 350;
	speed = randomSpeed();
	
}




Vector2 Ball::randomSpeed() {

	Vector2 ret;

	float x = GetRandomValue(0, 1);

	if (x == 0) {
		x = -8;
	}
	else if (x == 1) {
		x = 8;
	}

	float y = GetRandomValue(-8, 8);

	ret = { x, y };

	return ret;
}