#pragma once
#include "raylib.h";

class Ball
{
public:
	
	Ball();
	void Draw();
	void Update();
	Rectangle collision;
	Vector2 speed;
	int winner;
	Vector2 position;
private:

	void Respawn();
	
	
	Vector2 randomSpeed();
	

};

