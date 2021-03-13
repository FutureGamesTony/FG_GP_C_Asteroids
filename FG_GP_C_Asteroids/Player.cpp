#include "Player.h"
#include "SDL_image.h"
#include "PlayerSprite.h"
#include "PlayerCollider.h"
#include "Keyboard.h"
Player::Player()
{
    m_playerSprite = new PlayerSprite();
    //m_playerCollider = new PlayerCollider(playerEntity, size, position, movement, m_collider);
}

Player::~Player()
{
    delete m_playerSprite;
    m_playerSprite = nullptr;
}

void Player::ApplyLeftRotation()
{
    std::cout << "ROTATING LEFT" << std::endl;
}

void Player::ApplyRightRotation()
{
    std::cout << "ROTATING RIGHT" << std::endl;
}

void Player::ApplyAcceleration()
{
    std::cout << "ACCELERATING" << std::endl;
    position.yPosition = m_playerSprite->destinationRect.y;
	position.xPosition = m_playerSprite->destinationRect.x;
    movement.movementY = -3;
	movement.movementX = 0;
    UpdateMovement(movement.movementX,movement.movementY);
}

void Player::FireWeapon()
{
    std::cout << "PEW PEW" << std::endl;
}

void Player::CreateEntity(Entity_Type entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput)
{
}

void Player::Update() 
{
	UpdateMovement(movement.movementX, movement.movementY);
}

Size Player::SetSize()
{
    return Size();
}

Position Player::SetPosition()
{
    return Position();
}

void Player::UpdateMovement(float X, float Y)
{
	movement.movementY = Y;
	movement.movementX = X;
    m_playerSprite->destinationRect.y += movement.movementY;
	m_playerSprite->destinationRect.x += movement.movementX;
}

ISprite* Player::GetSprite()
{
    return m_playerSprite;
}

void Player::CreateSprite(SDL_Renderer* renderer)
{
}

ICollider* Player::GetCollider()
{
    return dynamic_cast<PlayerCollider*>(m_playerCollider);
}

Movement Player::SetMovementInput(Keyboard::PlayerInput moveCommand)
{
    if (moveCommand == Keyboard::PlayerForward) { ApplyAcceleration(); }
    else if (moveCommand == Keyboard::PlayerRotateLeft) { ApplyLeftRotation(); }
    else if (moveCommand == Keyboard::PlayerRotateRight) { ApplyRightRotation(); }
    else if (moveCommand == Keyboard::PlayerFireWeapon) { FireWeapon(); }
    return movement;
}
