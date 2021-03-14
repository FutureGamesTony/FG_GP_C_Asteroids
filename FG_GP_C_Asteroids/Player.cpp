#include "Player.h"
#include "SDL_image.h"
#include "PlayerSprite.h"
#include "PlayerCollider.h"
#include "Keyboard.h"
Player::Player()
{
    //m_playerSprite = new PlayerSprite();
    //m_playerCollider = new PlayerCollider(playerEntity, size, position, movement, m_collider);
}

Player::~Player()
{

}
int degrees = 0;
void Player::ApplyLeftRotation()
{

}

void Player::ApplyRightRotation()
{

}

void Player::ApplyAcceleration()
{

	
	movement.x = cos(degrees * M_PI / 1.8);
	movement.y = sin(degrees * M_PI / 1.8);
    UpdateMovement(movement.x, movement.y, position.x, position.y);
}

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

Position Player::SetPosition()
{
    return Position();
}

void Player::UpdateMovement(float moveX, float moveY, float xPos, float yPos)
{


;
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

Movement Player::SetMovementInput(EngineConfig::PlayerInput moveCommand)
{
	switch (moveCommand)
	{
	case EngineConfig::PlayerInput::NoKeyPressed:
		break;
	case EngineConfig::PlayerInput::PlayerForward:
		ApplyAcceleration();
		break;
	case EngineConfig::PlayerInput::PlayerRotateLeft:
		ApplyLeftRotation();
		break;
	case EngineConfig::PlayerInput::PlayerRotateRight:
		ApplyRightRotation();
		break;
	case EngineConfig::PlayerInput::PlayerFireWeapon:
		FireWeapon();
		break;
	default:
		break;
	}
    return movement;
}
