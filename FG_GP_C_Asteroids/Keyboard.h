#pragma once
#include "SDL.h"
#include <vector>

class Player;
class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	enum PlayerInput
	{
		NoKeyPressed,
		PlayerForward,
		PlayerRotateLeft,
		PlayerRotateRight,
		PlayerFireWeapon
	};

	bool GetEscapePressed();
	PlayerInput GetKeyDown();
	bool checkForwardPressed();
	bool checkRotateLeftPressed();
	bool checkRootateRightPressed();
	bool checkFireWeaponPressed();

	bool wPressed = false;
	bool aPressed = false;
	bool dPressed = false;
	bool spacePressed = false;
private:
	bool SetEscapePressed();
	void SetKeyDown();
	bool escapePressed;
	const Uint8* keystates = SDL_GetKeyboardState(NULL); // borrowed the InputCode in main
	SDL_Scancode buttonPressed;
};

