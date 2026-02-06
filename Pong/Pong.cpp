#include <iostream>
#include "raylib.h"
#include "Player1.h"
#include "Player2.h"
#include "Ball.h"
#include "AI.h"

enum Scene {MENU, ONE_GAME, TWO_GAME};

int main() {

	std::cout << "Game has been initialized.";

	InitWindow(1280, 720, "Pong");
	InitAudioDevice();
	
	SetTargetFPS(60);

	Player1 player1;
	Player2 player2;
	Ball ball;
	AI ai;

	Sound score = LoadSound("C:/Users/goktu/source/repos/Pong/Pong/score.wav");
	Sound hit = LoadSound("C:/Users/goktu/source/repos/Pong/Pong/hit.wav");

	int oneScore = 0;
	int twoScore = 0;

	Vector2 firstText = MeasureTextEx(GetFontDefault(), "ONE PLAYER", 50, 5);
	Vector2 secondText = MeasureTextEx(GetFontDefault(), "TWO PLAYER", 50, 5);
	Rectangle oneP = {440 - (firstText.x / 2), 400, firstText.x, firstText.y};
	Rectangle twoP = {840 - (secondText.x / 2), 400, secondText.x, secondText.y};

	Color firstButtonColor = WHITE;
	Color secondButtonColor = WHITE;

	Scene scene = MENU;

	while (!WindowShouldClose()) {


		switch (scene) {


		case MENU:

			BeginDrawing();


			DrawText("PONG", 640 - (MeasureText("PONG", 200) / 2), 150, 200, WHITE);
			DrawText("ONE PLAYER", oneP.x, oneP.y, 50, firstButtonColor);
			DrawText("TWO PLAYER", twoP.x, twoP.y, 50, secondButtonColor);




			EndDrawing();


			if (GetMousePosition().x > oneP.x && GetMousePosition().x < oneP.x + oneP.width && GetMousePosition().y > oneP.y && GetMousePosition().y < oneP.y + oneP.height) {
				firstButtonColor = YELLOW;
			}
			else {
				firstButtonColor = WHITE;
			}

			if (GetMousePosition().x > twoP.x && GetMousePosition().x < twoP.x + twoP.width && GetMousePosition().y > twoP.y && GetMousePosition().y < twoP.y + twoP.height) {
				secondButtonColor = YELLOW;
			}
			else {
				secondButtonColor = WHITE;
			}

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

				if (GetMousePosition().x > oneP.x && GetMousePosition().x < oneP.x + oneP.width && GetMousePosition().y > oneP.y && GetMousePosition().y < oneP.y + oneP.height) {
					scene = ONE_GAME;
				}

				if (GetMousePosition().x > twoP.x && GetMousePosition().x < twoP.x + twoP.width && GetMousePosition().y > twoP.y && GetMousePosition().y < twoP.y + twoP.height) {
					scene = TWO_GAME;
				}

			}


			break;


		case ONE_GAME:

			player1.Update();
			ai.Update();
			ball.Update();

			ai.ballPos = ball.position;
			ai.ballVector.x = ball.speed.x / 10;
			ai.ballVector.y = ball.speed.y / 10;



			switch (ball.winner) {

			case -1:

				oneScore++;
				ball.winner = 0;
				PlaySound(score);

				break;
			case 0:
				break;

			case 1:
				twoScore++;
				ball.winner = 0;
				PlaySound(score);
				break;
			}

			if (CheckCollisionRecs(ball.collision, player1.collision1) && ball.speed.x < 0) {

				ball.speed.x *= -1;

				ball.speed.y += 3;

				PlaySound(hit);

			}
			if (CheckCollisionRecs(ball.collision, player1.collision2) && ball.speed.x < 0) {

				ball.speed.x *= -1;
				ball.speed.x += 3;
				PlaySound(hit);
			}
			if (CheckCollisionRecs(ball.collision, player1.collision3) && ball.speed.x < 0) {

				ball.speed.x *= -1;
				ball.speed.y -= 3;
				PlaySound(hit);
			}

			if (CheckCollisionRecs(ball.collision, ai.collision1) && ball.speed.x > 0) {
				ball.speed.x *= -1;
				ball.speed.y += 3;

				PlaySound(hit);
			}
			if (CheckCollisionRecs(ball.collision, ai.collision2) && ball.speed.x > 0) {
				ball.speed.x *= -1;
				ball.speed.x -= 3;
				PlaySound(hit);
			}
			if (CheckCollisionRecs(ball.collision, ai.collision3) && ball.speed.x > 0) {
				ball.speed.x *= -1;
				ball.speed.y -= 3;
				PlaySound(hit);
			}



			BeginDrawing();

			ClearBackground(BLACK);

			DrawText(TextFormat("%d", oneScore), 70, 0, 125, WHITE);
			DrawText(TextFormat("%d", twoScore), 1130, 0, 125, WHITE);

			player1.Draw();
			ai.Draw();
			ball.Draw();




			EndDrawing();




			break;


		case TWO_GAME:
			player1.Update();
			player2.Update();
			ball.Update();


			switch (ball.winner) {

			case -1:

				oneScore++;
				ball.winner = 0;
				PlaySound(score);
				
				break;
			case 0:
				break;

			case 1:
				twoScore++;
				ball.winner = 0;
				PlaySound(score);

				break;
			}


			if (CheckCollisionRecs(ball.collision, player1.collision1) && ball.speed.x < 0) {

				ball.speed.x *= -1;

				ball.speed.y += 3;

				PlaySound(hit);



			}
			if (CheckCollisionRecs(ball.collision, player1.collision2) && ball.speed.x < 0) {

				ball.speed.x *= -1;
				ball.speed.x += 3;
				PlaySound(hit);
			}
			if (CheckCollisionRecs(ball.collision, player1.collision3) && ball.speed.x < 0) {

				ball.speed.x *= -1;
				ball.speed.y -= 3;
				PlaySound(hit);
			}

			if (CheckCollisionRecs(ball.collision, player2.collision1) && ball.speed.x > 0) {
				ball.speed.x *= -1;
				ball.speed.y += 3;
				PlaySound(hit);


			}
			if (CheckCollisionRecs(ball.collision, player2.collision2) && ball.speed.x > 0) {
				ball.speed.x *= -1;
				ball.speed.x -= 3;
				PlaySound(hit);
			}
			if (CheckCollisionRecs(ball.collision, player2.collision3) && ball.speed.x > 0) {
				ball.speed.x *= -1;
				ball.speed.y -= 3;
				PlaySound(hit);
			}



			BeginDrawing();

			ClearBackground(BLACK);

			DrawText(TextFormat("%d", oneScore), 70, 0, 125, WHITE);
			DrawText(TextFormat("%d", twoScore), 1130, 0, 125, WHITE);

			player1.Draw();
			player2.Draw();
			ball.Draw();




			EndDrawing();

			break;
		
		}
	}

	UnloadSound(hit);
	UnloadSound(score);
	
	CloseAudioDevice();
	CloseWindow();


	return 0;
}