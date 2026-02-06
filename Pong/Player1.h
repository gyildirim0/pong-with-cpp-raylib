#pragma once
#include "raylib.h"

class Player1
{
	public:
		Player1();
		void Draw();
		void Update();
		Rectangle collision1;
		Rectangle collision2;
		Rectangle collision3;
	private:
		Vector2 position;
		int speed = 5;
		

};

