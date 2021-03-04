#pragma once
#include "sEntity.h"
#include <vector>

class Asteroid : sEntity
{
public:
	void Split();
	void Explode();
	void Advance();
	void Draw();

	static std::vector<Asteroid> asteroids;

	Asteroid(float xPos, float yPos, float velocityX, float velocityY, int size)
	{
	}


	/*
	Asteroid(){} // split constructor
	~Asteroid()
	{

	};
	*/
};

