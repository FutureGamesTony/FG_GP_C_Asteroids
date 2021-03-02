#pragma once
#include <vector>

class Asteroid
{
private:
	void Split();
	void Explode();
	void Advance();
	void Draw();
	void CreateAsteroid();
public:
	int population;

	float xPos;
	float yPos;
	float velocityX;
	float velocityY;
	int size;
	float angle;
	float roatationSpeed;

	static std::vector<Asteroid> asteroids;

	Asteroid(float xPos, float yPos, float velocityX, float velocityY, int size){} // start of the game constructor

	Asteroid(){} // split constructor
	~Asteroid()
	{

	};
};

