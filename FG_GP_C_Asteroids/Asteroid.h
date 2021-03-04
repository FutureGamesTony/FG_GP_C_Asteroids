#pragma once
#include "sEntity.h"

class Asteroid : sEntity
{
public:
	void Split();
	void Explode();
	void Advance();
	void Draw();

	Asteroid(float x, float y, float velX, float velY, int size)
	{
		
	}

};

