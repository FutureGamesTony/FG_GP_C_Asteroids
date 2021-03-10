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

std::vector<Keyboard::PlayerInput> Keyboard::GetKeyDown()
{
	SetKeyDown();
	return playerInput;
}

void Keyboard::RemoveElemement(PlayerInput input)
{
	for (int i = 0; i < playerInput.size(); i++)
	{
		if (i == input)
		{
			playerInput.erase(playerInput.begin() + i);
			playerInput.shrink_to_fit();
		}
	}
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
				playerInput.push_back(PlayerForward);
				break;

			case SDLK_a:
				cout << "A pressed\n";
				playerInput.push_back(PlayerRotateLeft);
				break;

			case SDLK_s:
				cout << "S pressed\n";
				//nothing should happen
				break;

			case SDLK_d:
				cout << "D pressed\n";
				playerInput.push_back(PlayerRotateRight);
				break;

			case SDLK_SPACE:
				cout << "Space pressed\n";
				playerInput.push_back(PlayerShoot);
				//spacePressed = true;
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
				cout << "W pressed\n";
				RemoveElemement(PlayerForward);
				break;

			case SDLK_a:
				cout << "A pressed\n";
				RemoveElemement(PlayerRotateLeft);
				break;

			case SDLK_s:
				cout << "S pressed\n";
				break;

			case SDLK_d:
				cout << "D pressed -  :(\n";
				RemoveElemement(PlayerRotateRight);
				break;

			case SDLK_SPACE:
				cout << "Space pressed - pew pew\n";
				RemoveElemement(PlayerShoot);
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
