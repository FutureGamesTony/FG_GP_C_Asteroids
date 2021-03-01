#pragma once

class Keyboard;
class Mouse;
class InputManager
{
public:
	InputManager();
	~InputManager();
	void GetKey();
	bool QuitApplication();
private:
	Keyboard* keyboard;
	Mouse* mouse;

};

