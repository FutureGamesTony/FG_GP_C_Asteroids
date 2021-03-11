#include "Player.h"
#include "Keyboard.h"
#include <iostream>
using std::cout;
Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}



bool Keyboard::GetEscapePressed()
{
	return escapePressed;
}

Keyboard::PlayerInput Keyboard::GetKeyDown()
{
	SetKeyDown();
	if (wPressed) return PlayerForward;
	else if (aPressed) return PlayerRotateLeft;
	else if (dPressed) return PlayerRotateRight;
	else if (spacePressed) return PlayerFireWeapon;
	else return NoKeyPressed;
}
bool Keyboard::checkForwardPressed()
{
	return wPressed;
}
bool Keyboard::checkRotateLeftPressed()
{
	return aPressed;
}
bool Keyboard::checkRootateRightPressed()
{
	return dPressed;
}
bool Keyboard::checkFireWeaponPressed()
{
	return spacePressed;
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
				wPressed = true;
				break;

			case SDLK_a:
				cout << "A pressed\n";
				aPressed = true;
				break;

			case SDLK_s:
				cout << "S pressed\n";
				//nothing should happen
				break;

			case SDLK_d:
				cout << "D pressed - :(\n";
				dPressed = true;
				break;

			case SDLK_SPACE:
				cout << "Space pressed - pew pew\n";
				spacePressed = true;
				break;

			case SDLK_ESCAPE:
				cout << "Escape pressed\n";
				//QuitGame()
				escapePressed = true;
				break;

			case SDLK_F11:
				cout << "F11 pressed\n";
				//ToggleFullscreen()
				break;

			default:
				break;
			}
		}
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_w:
				cout << "W released\n";
				wPressed = false;
				break;

			case SDLK_a:
				cout << "A released\n";
				aPressed = false;
				break;

			case SDLK_s:
				cout << "S released\n";
				break;

			case SDLK_d:
				cout << "D released -  :(\n";
				dPressed = false;
				break;

			case SDLK_SPACE:
				cout << "Space released\n";
				spacePressed = false;
				break;

			case SDLK_ESCAPE:
				cout << "Escape released\n";
				escapePressed = false;
				break;
			default:
				break;
			}
		}
	}
}
