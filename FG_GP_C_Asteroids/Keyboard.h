#pragma once
#include "SDL.h"
class Player;
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	void GetKeyDown();
	bool GetEscapePressed();
private:
	bool SetEscapePressed();
	void SetKeyDown();
	bool escapePressed;
	const Uint8* keystates = SDL_GetKeyboardState(NULL); // borrowed the InputCode in main
	SDL_Scancode buttonPressed;
};

