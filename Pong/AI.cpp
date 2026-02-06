#include "AI.h"

AI::AI() {


	position.x = 1200;
	position.y = 210;


	collision1.width = 30;
	collision1.height = 50;
	collision2.width = 30;
	collision2.height = 50;
	collision3.width = 30;
	collision3.height = 50;
}

void AI::Draw() {

	DrawRectangle(position.x, position.y, 30, 150, WHITE);
	DrawLine(ballPos.x + 10, ballPos.y + 10, (ballPos.x + 10) + (ballVector.x * 30), (ballPos.y + 10) - (ballVector.y * 30), WHITE);
	
}

void AI::Update() {

	if (((ballPos.y + 10) - (ballVector.y * 30)) < position.y + 75 && ballVector.x > 0 && position.y > 0) {

		position.y -= speed;

	}
	else if (((ballPos.y + 10) - (ballVector.y * 30)) > position.y + 75 && ballVector.x > 0 && position.y < 570) {

		position.y += speed;

	}
	



	collision1.x = position.x;
	collision1.y = position.y;
	collision2.x = position.x;
	collision2.y = position.y + 50;
	collision3.x = position.x;
	collision3.y = position.y + 100;
}

