#pragma once
#include "sEntity.h"

class Asteroid : sEntity
{
public:
	void Split();
	void Explode();
	void Advance();
	float getXpos();
	float getYpos();
	float getXvelocity();
	float getYvelocity();
	int getSize();

	Asteroid(float x, float y, float velX, float velY, int passedsize)
	{
		xPos = x;
		yPos = y;
		velocityX = velX;
		velocityY = velY;
		size = passedsize;
	}

};

