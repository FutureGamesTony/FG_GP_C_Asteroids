#include "Asteroid.h"
#include "EngingConfig.h"
#include "RenderManager.h"

float Asteroid::getXpos()
{
	return this->xPos;
}

float Asteroid::getYpos()
{
	return this->yPos;
}

float Asteroid::getXvelocity()
{
	return this->velocityX;
}

float Asteroid::getYvelocity()
{
	return this->velocityY;
}

void Asteroid::ModifyRects()
{
}

int Asteroid::getSize()
{
	return this->size;
}
