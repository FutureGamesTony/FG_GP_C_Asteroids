#pragma once
#include "SDL.h"
#include <vector>
#include "EngingConfig.h"
class Player;
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	EngineConfig::PlayerInput GetKeyDown();
private:
	EngineConfig::PlayerInput SetKeyDown();
	const Uint8* keystates = SDL_GetKeyboardState(NULL); // borrowed the InputCode in main
	EngineConfig::PlayerInput e_keyPressed;

};

