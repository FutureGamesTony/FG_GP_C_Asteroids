#include "InputManager.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "SDL.h"

InputManager::InputManager()
{
	keyboard = new Keyboard();
	mouse = new Mouse();
}

InputManager::~InputManager()
{
	delete keyboard;
	keyboard = nullptr;
	delete mouse;
	mouse = nullptr;
}
