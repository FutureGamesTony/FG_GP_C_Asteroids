#pragma once
#include "Keyboard.h"

class Keyboard;
class Mouse;
class Player;
class IEntity;
class InputManager
{
public:
	InputManager();
	~InputManager();
	void GetKey(IEntity* player, int rotation, int x, int y);
	bool QuitApplication();
	void GetMousePosition(int x, int y);
	EngineConfig::PlayerInput GetInput();
private:
	Keyboard* keyboard;
	Mouse* mouse;
	EngineConfig::PlayerInput getKeyPressed;

};

