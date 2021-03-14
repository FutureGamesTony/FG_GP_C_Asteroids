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



	bool GetEscapePressed();
	EngineConfig::PlayerInput GetKeyDown();
	int checkForwardPressed(int x, int y);
	int checkRotateLeftPressed(int rotateLeft);
	int checkRootateRightPressed(int rotateRight);
	bool checkFireWeaponPressed();
	bool wPressed = false;
	bool aPressed = false;
	bool dPressed = false;
	bool spacePressed = false;
private:
	bool SetEscapePressed();
	EngineConfig::PlayerInput SetKeyDown();
	bool escapePressed;
	const Uint8* keystates = SDL_GetKeyboardState(NULL); // borrowed the InputCode in main

	EngineConfig::PlayerInput e_keyPressed;

};

