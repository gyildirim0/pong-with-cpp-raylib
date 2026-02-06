#include "Player2.h"

Player2::Player2() {

	position.x = 1200;
	position.y = 210;

	collision1.width = 30;
	collision1.height = 50;
	collision2.width = 30;
	collision2.height = 50;
	collision3.width = 30;
	collision3.height = 50;

}

void Player2::Draw() {

	DrawRectangle(position.x, position.y, 30, 150, WHITE);

}

void Player2::Update() {

	if (IsKeyDown(KEY_DOWN) && position.y != 570) {

		position.y += speed;

	}
	if (IsKeyDown(KEY_UP) && position.y != 0) {

		position.y -= speed;

	}

	collision1.x = position.x;
	collision1.y = position.y;
	collision2.x = position.x;
	collision2.y = position.y + 50;
	collision3.x = position.x;
	collision3.y = position.y + 100;

}