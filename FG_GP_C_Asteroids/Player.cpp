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
    std::cout << "ROTATING LEFT" << std::endl;
}

void Player::ApplyRightRotation()
{
    std::cout << "ROTATING RIGHT" << std::endl;
}

void Player::ApplyAcceleration()
{
    std::cout << "ACCELERATING" << std::endl;
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
}

Size Player::SetSize()
{
    return Size();
}

Position Player::SetPosition()
{
    return Position();
}

Movement Player::SetMovementInput(std::vector<Keyboard::PlayerInput> inputList)
{
    for (int i = 0; i < inputList.size(); i++)
    {
        switch (inputList[i])
        {
        case Keyboard::PlayerForward:
            ApplyAcceleration();
            break;

        case Keyboard::PlayerRotateLeft:
            ApplyLeftRotation();
            break;

        case Keyboard::PlayerRotateRight:
            ApplyRightRotation();
            break;

        case Keyboard::PlayerShoot:
            FireWeapon();
            break;
        default:
            break;
        }
    }
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
