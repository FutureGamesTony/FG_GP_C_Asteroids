#pragma once

class Keyboard;
class Mouse;
class Player;
class IEntity;
class InputManager
{
public:
	InputManager();
	~InputManager();
	void GetKey(IEntity* player);
	bool QuitApplication();
private:
	Keyboard* keyboard;
	Mouse* mouse;

};

