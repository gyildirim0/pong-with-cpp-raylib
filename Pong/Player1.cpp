#include "Player1.h"

Player1::Player1() {
	position.x = 50;
	position.y = 210;
	
	collision1.width = 30;
	collision1.height = 50;
	collision2.width = 30;
	collision2.height = 50;
	collision3.width = 30;
	collision3.height = 50;

}

void Player1::Draw() {

	DrawRectangle(position.x, position.y, 30, 150, WHITE);
}

void Player1::Update() {

	if (IsKeyDown(KEY_S) && position.y != 570) {
		position.y += speed;
	}
	if (IsKeyDown(KEY_W) && position.y != 0) {
		position.y -= speed;
	}

	collision1.x = position.x;
	collision1.y = position.y;
	collision2.x = position.x;
	collision2.y = position.y + 50;
	collision3.x = position.x;
	collision3.y = position.y + 100;

}