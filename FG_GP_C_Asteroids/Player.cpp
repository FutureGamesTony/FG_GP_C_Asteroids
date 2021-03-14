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
	//position.y = m_playerSprite->destinationRect.y;
	//position.x = m_playerSprite->destinationRect.x;

    //std::cout << "ROTATING LEFT" << std::endl;
	//if (degrees > 360) degrees == 0;
	//if (degrees < 0) degrees == 360;
	//degrees--;
	//m_playerSprite->ModifyDegrees(degrees * M_PI / 1.8);
	//std::cout << ((degrees * M_PI / 1.8)) << ", " << ((degrees * M_PI / 1.8)) << std::endl;
}

void Player::ApplyRightRotation()
{
	//position.y = m_playerSprite->destinationRect.y;
	//position.x = m_playerSprite->destinationRect.x;

 //   //std::cout << "ROTATING RIGHT" << std::endl;
	//if (degrees > 360) degrees == 0;
	//if (degrees < 0) degrees == 360;
	//degrees++;
	//m_playerSprite->ModifyDegrees(degrees * M_PI / 1.8);
	//std::cout << ((degrees * M_PI / 1.8)) << ", " << ((degrees * M_PI / 1.8)) << std::endl;
}

void Player::ApplyAcceleration()
{
	//position.y = m_playerSprite->destinationRect.y;
	//position.x = m_playerSprite->destinationRect.x;
	//int x;
	//int y;
	//SDL_GetMouseState(&x, &y);
	//std::cout << "x: " << x << ", y: " << y << "\n";
	//movement.x = position.x - x;
	//movement.y = position.y - y;
	//movement.x = movement.x / sqrt(pow(movement.x, 2) + (movement.y, 2));
	//movement.y = movement.y / sqrt(pow(movement.x, 2) + (movement.y, 2));
	//m_playerSprite->SetDestinationRect(movement.x, movement.y);
 //   std::cout << movement.x << ", " << movement.y << std::endl;
	
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
	//UpdateMovement(movement.x, movement.y, position.x, position.y);
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
	//moveX = moveX + xPos;
	//moveY = moveY + yPos;
	
    //m_playerSprite->SetDestinationRect (moveX, moveY);

;
}

ISprite* Player::GetSprite()
{
    return m_playerSprite;
}

void Player::CreateSprite(SDL_Renderer* renderer)
{
	//m_playerSprite = new PlayerSprite(renderer);
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
    //if (moveCommand == Keyboard::PlayerForward) { ApplyAcceleration(); }
    //else if (moveCommand == Keyboard::PlayerRotateLeft) { ApplyLeftRotation(); }
    //else if (moveCommand == Keyboard::PlayerRotateRight) { ApplyRightRotation(); }
    //else if (moveCommand == Keyboard::PlayerFireWeapon) { FireWeapon(); }
    return movement;
}
