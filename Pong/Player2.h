#pragma once
#include "raylib.h"

class Player2
{

	public:
		Player2();

		void Draw();
		void Update();
		Rectangle collision1;
		Rectangle collision2;
		Rectangle collision3;
	private:
		
		Vector2 position;
		int speed = 5;
		

};

