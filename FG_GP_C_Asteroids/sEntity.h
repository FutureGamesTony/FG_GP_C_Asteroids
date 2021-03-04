#pragma once
#include "SDL.h"
#include <vector>

struct sEntity
{
public:
	static std::vector<Asteroid> asteroids;

	float xPos;
	float yPos;
	float velocityX;
	float velocityY;
	float angle;
	float roatationSpeed;
};

