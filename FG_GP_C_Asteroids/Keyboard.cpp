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

EngineConfig::PlayerInput Keyboard::GetKeyDown()
{
	return SetKeyDown();
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
				//return e_keyPressed;
				break;
			case SDLK_a:
				e_keyPressed = EngineConfig::PlayerInput::PlayerRotateLeft;
				//return e_keyPressed;
				break;
			case SDLK_s:
				e_keyPressed = EngineConfig::PlayerInput::PlayerBreak;
				//return e_keyPressed;
				break;
			case SDLK_d:
				e_keyPressed = EngineConfig::PlayerInput::PlayerRotateRight;
				//return e_keyPressed;
				break;
			case SDLK_SPACE:
				e_keyPressed = EngineConfig::PlayerInput::PlayerFireWeapon;
				//return e_keyPressed;
				break;
			case SDLK_ESCAPE:
				e_keyPressed = EngineConfig::PlayerInput::PlayerQuit;
				cout << "Escape pressed\n";
				//QuitGame()
				//return e_keyPressed;
				break;
			case SDLK_F11:
				cout << "F11 pressed\n";
				break;
			default:
				break;
			}
			return e_keyPressed;
		}
		if (e.type == SDL_KEYUP)
		{
			e_keyPressed = EngineConfig::PlayerInput::NoKeyPressed;
			return e_keyPressed;
		}
	}
	return e_keyPressed;
}
