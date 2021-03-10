#include "Player.h"
#include "SDL_image.h"
#include "PlayerSprite.h"
#include "PlayerCollider.h"

Player::Player(SDL_Renderer* renderer)
{
    m_playerSprite = new PlayerSprite(renderer);
    m_playerCollider = new PlayerCollider(playerEntity, size, position, movement, m_collider);
}

Player::~Player()
{
    delete m_playerSprite;
    m_playerSprite = nullptr;
}

void Player::ApplyLeftRotation()
{

}

void Player::ApplyRightRotation()
{
}

void Player::ApplyAcceleration()
{
}

void Player::FireWeapon()
{
}

void Player::CreateEntity(Entity_Type entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput)
{
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

Movement Player::SetMovementInput()
{
    return Movement();
}

void Player::UpdateMovement()
{
}

ISprite* Player::GetSprite()
{
    return (m_playerSprite);
}

ICollider* Player::GetCollider()
{
    return dynamic_cast<PlayerCollider*>(m_playerCollider);
}
