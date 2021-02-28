#pragma once
#include "SDL.h"
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	void GetKeyDown();
private:

	void SetKeyDown();
	const Uint8* keystates = SDL_GetKeyboardState(NULL); // borrowed the InputCode in main
	SDL_Scancode buttonPressed;
};

