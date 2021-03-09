#pragma once
#include "ICollider.h"
#include <vector>
class AsteroidCollider : public ICollider
{
public:
    AsteroidCollider(int x, int y);
    void CreateCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider, Circle circleCollider) override;
    //The dimensions of the dot

    //Maximum axis velocity of the dot
    static const int DOT_VEL = 1;

    //Initializes the variables

    //Takes key presses and adjusts the dot's velocity
    void HandleEvent(SDL_Event& e);

    //Moves the dot and checks collision
    void Move();

    //Shows the dot on the screen
    void Render();

    //Gets collision circle
    Circle& GetCollider();
    void IsCollided(bool collision);
private:
    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;
    bool isCoolided = false;
    //Dot's collision circle
    Circle m_Collider;
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;
    //Moves the collision circle relative to the dot's offset
    void ShiftColliders();
};

