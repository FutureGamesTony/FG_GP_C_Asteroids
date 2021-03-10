#include "InputManager.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Player.h"
//#include "SDL.h"

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

void InputManager::GetKey(IEntity* player)
{
	player->SetMovementInput(keyboard->GetKeyDown());
}

bool InputManager::QuitApplication()
{
	return keyboard->GetEscapePressed();
}
