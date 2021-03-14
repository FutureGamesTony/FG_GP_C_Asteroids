#include "Mouse.h"
#include "SDL.h"
#include <iostream>
Mouse::Mouse()
{
}

Mouse::~Mouse()
{
}

void Mouse::GetMousePosition(int xPos, int yPos)
{
	SDL_GetMouseState(&xPos, &yPos);
}
