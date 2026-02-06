#pragma once
#include "raylib.h"

class AI
{

public:
	AI();

	void Draw();
	void Update();
	Rectangle collision1;
	Rectangle collision2;
	Rectangle collision3;
	Vector2 ballVector;
	Vector2 ballPos;


private:

	Vector2 position;
	int speed = 5;


};

