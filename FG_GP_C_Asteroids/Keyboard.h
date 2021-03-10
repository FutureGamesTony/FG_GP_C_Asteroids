#pragma once
#include "SDL.h"
#include <vector>

class Player;
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	bool GetEscapePressed();
	enum PlayerInput
	{
		PlayerForward,
		PlayerRotateLeft,
		PlayerRotateRight,
		PlayerShoot
	};
	std::vector<PlayerInput> playerInput;
	std::vector<PlayerInput> GetKeyDown();
private:
	void RemoveElemement(PlayerInput input);
	bool SetEscapePressed();
	void SetKeyDown();
	bool escapePressed;
	const Uint8* keystates = SDL_GetKeyboardState(NULL); // borrowed the InputCode in main
	SDL_Scancode buttonPressed;
};

