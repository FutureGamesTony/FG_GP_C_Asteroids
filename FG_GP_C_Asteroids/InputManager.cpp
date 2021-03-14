#include "InputManager.h"
#include "Mouse.h"
#include "Player.h"


InputManager::InputManager()
{
	keyboard = new Keyboard();
	mouse = new Mouse();
	getKeyPressed == EngineConfig::PlayerInput::NoKeyPressed;
}

InputManager::~InputManager()
{
	delete keyboard;
	keyboard = nullptr;
	delete mouse;
	mouse = nullptr;
}

void InputManager::GetKey(IEntity* player, int rotation, int x, int y)
{
	keyboard->GetKeyDown();
	getKeyPressed = keyboard->GetKeyDown();
}

bool InputManager::QuitApplication()
{
	return keyboard->GetEscapePressed();
}

void InputManager::GetMousePosition(int x, int y)
{
	mouse->GetMousePosition(x, y);
}

EngineConfig::PlayerInput InputManager::GetInput()
{
	return keyboard->GetKeyDown();
}
