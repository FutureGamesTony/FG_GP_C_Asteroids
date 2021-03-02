#include "Asteroid.h"

Asteroid::Asteroid(float xPos, float yPos, float velocityX, float velocityY, int size) // start of the game constructor
{
	CreateAsteroid();
}
Asteroid::Asteroid() // split constructor
{

}
Asteroid::~Asteroid()
{

}

void Asteroid::CreateAsteroid()
{
	asteroids.push_back({ 20.0f, 20.0f, 8.0f, -6.0f, 16 });
}
