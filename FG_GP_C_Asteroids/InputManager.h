#pragma once

class Keyboard;
class Mouse;
class InputManager
{
public:
	InputManager();
	~InputManager();
private:
	Keyboard* keyboard;
	Mouse* mouse;
};

