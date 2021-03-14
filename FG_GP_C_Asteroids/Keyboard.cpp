#include "Player.h"
#include "Keyboard.h"
#include <iostream>
#include <math.h>
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

EngineConfig::PlayerInput Keyboard::GetKeyDown()
{
	//SetKeyDown();
	return SetKeyDown();
}
int Keyboard::checkForwardPressed(int x, int y)
{
	
	if (x != 0) return round(y / x);
	else return 0;
}
int Keyboard::checkRotateLeftPressed(int rotation)
{
	rotation--;
	if (rotation < 0)rotation = 360;
	return rotation;
}
int Keyboard::checkRootateRightPressed(int rotation)
{
	rotation++;
	if (rotation > 360) rotation = 0;
	return rotation;
}
bool Keyboard::checkFireWeaponPressed()
{
	return spacePressed;
}

EngineConfig::PlayerInput Keyboard::SetKeyDown()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_w:
				e_keyPressed = EngineConfig::PlayerInput::PlayerForward;
				wPressed = true;
				return e_keyPressed;
				break;

			case SDLK_a:
				e_keyPressed = EngineConfig::PlayerInput::PlayerRotateLeft;
				aPressed = true;
				return e_keyPressed;
				break;

			case SDLK_s:
				e_keyPressed = EngineConfig::PlayerInput::PlayerBreak;
				return e_keyPressed;
				break;

			case SDLK_d:
				e_keyPressed = EngineConfig::PlayerInput::PlayerRotateRight;
				dPressed = true;
				return e_keyPressed;
				break;

			case SDLK_SPACE:
				e_keyPressed = EngineConfig::PlayerInput::PlayerFireWeapon;
				spacePressed = true;
				return e_keyPressed;
				break;

			case SDLK_ESCAPE:
				e_keyPressed = EngineConfig::PlayerInput::PlayerQuit;
				cout << "Escape pressed\n";
				//QuitGame()
				escapePressed = true;
				return e_keyPressed;
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
			e_keyPressed = EngineConfig::PlayerInput::NoKeyPressed;
			return e_keyPressed;
		}
	}
	return e_keyPressed;
}
