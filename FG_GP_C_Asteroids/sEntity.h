#pragma once
#include "SDL.h"
#include <vector>
class Asteroid;
struct sEntity
{
public:
	static std::vector<Asteroid> asteroids;

	float xPos;
	float yPos;
	float velocityX;
	float velocityY;
	int size;
	float angle;
	float roatationSpeed;
};

