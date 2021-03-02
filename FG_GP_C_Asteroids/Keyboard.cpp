#include "Keyboard.h"
#include "Player.h"
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
	Player player;
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_w:
				cout << "W pressed\n";
				if (!player.isDead)
				{
					player.ApplyAcceleration();
				}
				break;
			case SDLK_a:
				cout << "A pressed\n";
				if (!player.isDead)
				{
					player.ApplyLeftRotation();
				}
				break;
			case SDLK_s:
				cout << "S pressed\n";
				//nothing should happen
				break;
			case SDLK_d:
				cout << "D pressed\n";
				if (!player.isDead) 
				{
					player.ApplyRightRotation();
				}
				break;
			case SDLK_SPACE:
				player.FireWeapon();
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
			case SDLK_ESCAPE:
				cout << "Escape released\n";
				escapePressed = false;
			default:
				break;
			}
		}
	}
}
