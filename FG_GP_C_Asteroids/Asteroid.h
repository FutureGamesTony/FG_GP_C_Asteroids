#pragma once
#include "SDL.h"
#include <vector>

class Asteroid
{

public:
	void Split();
	void Explode();
	void Advance();
	void Draw();

	int population;

	float xPos;
	float yPos;
	float velocityX;
	float velocityY;
	int size;
	float angle;
	float roatationSpeed;

	static std::vector<Asteroid> asteroids;

	Asteroid(float xPos, float yPos, float velocityX, float velocityY, int size) //constructor
	{
		asteroids.push_back({ xPos, yPos, velocityX, velocityY, size });
	}

	/*
	Asteroid(){} // split constructor
	~Asteroid()
	{

	};
	*/
};

