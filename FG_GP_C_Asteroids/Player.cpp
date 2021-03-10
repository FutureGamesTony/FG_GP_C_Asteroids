#include "Player.h"
#include "SDL_image.h"
#include "PlayerSprite.h"
#include "Keyboard.h"

Player::Player(SDL_Renderer* renderer)
{
    m_playerSprite = new PlayerSprite(renderer);
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
    std::cout << "SHOOTING" << std::endl;
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
        if (inputList[i] == Keyboard::PlayerForward)
        {
            ApplyAcceleration();
        }
        if (inputList[i] == Keyboard::PlayerRotateLeft)
        {
            ApplyLeftRotation();
        }
        if (inputList[i] == Keyboard::PlayerRotateRight)
        {
            ApplyRightRotation();
        }
        if (inputList[i] == Keyboard::PlayerShoot)
        {
            FireWeapon();
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
