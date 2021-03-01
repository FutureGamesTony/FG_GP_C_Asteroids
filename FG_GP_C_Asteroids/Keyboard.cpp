#include "Keyboard.h"
#include <iostream>
using std::cout;
Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

void Keyboard::GetKeyDown()
{
	SetKeyDown();
}

bool Keyboard::GetEscapePressed()
{
	return escapePressed;
}



void Keyboard::SetKeyDown()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_w:
				cout << "W pressed\n";
				break;
			case SDLK_a:
				cout << "A pressed\n";
				break;
			case SDLK_s:
				cout << "S pressed\n";
				break;
			case SDLK_d:
				cout << "D pressed\n";
				break;
			case SDLK_ESCAPE:
				cout << "Escape pressed\n";
				escapePressed = true;
				break;
			case SDLK_F11:
				cout << "F11 pressed\n";
				break;
			default:
				break;
			}
		}
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				cout << "Escape released\n";
				escapePressed = false;
			default:
				break;
			}
		}
	}
}
