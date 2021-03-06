#pragma once
#include "IEntity.h"

class Asteroid : IEntity
{
public:
	void Update() override;
	void Split();
	void Explode();
	void Advance();
	void Draw();

	Asteroid(float x, float y, float velX, float velY, int size)
	{

	}

};

