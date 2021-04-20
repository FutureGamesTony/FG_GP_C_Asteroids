#include "Player.h"
#include "SDL_image.h"
#include "PlayerSprite.h"
#include "PlayerCollider.h"

Player::Player(EngineConfig::EntityType entityType, ISprite* playerSprite, ICollider* playerCollider, Position position, double rotation)
{
	playerEntity = entityType;
	m_playerSprite = playerSprite;
	m_playerCollider = playerCollider;
	m_playerRotation = rotation;
	keyPressed = EngineConfig::PlayerInput::NoKeyPressed;
	m_collider = new SDL_Rect();
	playerMovement = { 0,0 };
    //m_playerSprite = new PlayerSprite();
    //m_playerCollider = new PlayerCollider(playerEntity, size, position, movement, m_collider);
}

Player::~Player()
{

}
int degrees = 0;


void Player::FireWeapon()
{
    std::cout << "PEW PEW" << std::endl;
}

void Player::CreateEntity(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput)
{
	CreatePlayer(entityType, window, renderer, renderIndex, renderFlags, sprite, collider, image, spriteFilePath, circle, position, movementInput);
}

void Player::Update() 
{

}

Size Player::SetSize()
{
    return Size();
}

Position Player::GetPosition()
{
	return playerPosition;
}

Position Player::SetPosition()
{
	return playerPosition;
}

double Player::GetRotation()
{
	return playerRotation;
}


ISprite* Player::GetSprite()
{
    return m_playerSprite;
}

void Player::CreateSprite(SDL_Renderer* renderer)
{

}

EngineConfig::EntityType Player::GetEntityType()
{
	return playerEntity;
}

ICollider* Player::GetCollider()
{
    return m_playerCollider;
}

void Player::CreatePlayer(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* playerSprite, ICollider* playerCollider, SDL_Surface* surface, char* spriteFilePath, Circle circle, Position position, Movement movement)
{
	
	entityType = playerEntity;
}

Position Player::SetPlayerPosition()
{
	double moveX = cos(((m_playerRotation + 270.0)) * 3.14159265 / 180) * movementSpeed;
	double moveY = sin(((m_playerRotation + 90.0)) * 3.14159265 / 180) * -movementSpeed;

	playerPosition.x += moveX;
	playerPosition.y += moveY;

	if (playerPosition.x > EngineConfig::WIDTH) playerPosition.x = 0;
	if (playerPosition.x < 0) playerPosition.x = EngineConfig::WIDTH;
	if (playerPosition.y > EngineConfig::HEIGHT) playerPosition.y = 0;
	if (playerPosition.y < 0) playerPosition.y = EngineConfig::HEIGHT;
	if (m_playerRotation > 360) m_playerRotation = m_playerRotation - 360;
	if (m_playerRotation < 0) m_playerRotation = m_playerRotation + 360;
	std::cout << "PlayerMovement: " << moveX << ", " << moveY << "\n";
	return playerPosition;
}

int Player::SetPlayerRotation()
{
	switch (keyPressed)
	{

	case EngineConfig::PlayerInput::PlayerRotateLeft:
		m_playerRotation--;
		break;
	case EngineConfig::PlayerInput::PlayerRotateRight:
		m_playerRotation++;
		break;
	}
	return m_playerRotation;
}

Movement Player::SetMovementInput(EngineConfig::PlayerInput moveCommand)
{
	switch (moveCommand)
	{
	case EngineConfig::PlayerInput::NoKeyPressed:
		break;
	case EngineConfig::PlayerInput::PlayerForward:
		SetPlayerPosition();
		break;
	case EngineConfig::PlayerInput::PlayerRotateLeft:
		SetPlayerRotation();
		break;
	case EngineConfig::PlayerInput::PlayerRotateRight:
		SetPlayerRotation();
		break;
	case EngineConfig::PlayerInput::PlayerBreak:
		break;
	case EngineConfig::PlayerInput::PlayerFireWeapon:
		break;
	case EngineConfig::PlayerInput::PlayerQuit:
		break;
	default:
		break;
	}
    return playerMovement;
}
