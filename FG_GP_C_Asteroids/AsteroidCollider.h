#pragma once
#include "ICollider.h"
#include <vector>
class PlayerCollider;
class AsteroidCollider;
class BulletCollider;
class AsteroidCollider : public ICollider
{
public:
    AsteroidCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, Circle circleCollider);
    void CreateCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider, Circle circleCollider) override;
    void DrawCollider();
    Position SetColliderPosition(Position colliderPosition);
    Size GetCollider();
    Position GetPosition();
    bool HasCollided();
    bool Collision(bool collision);
private:
    Position position;
    Size size;
    bool hasCollided = false;
    PlayerCollider* m_playerCollider;
    std::vector<AsteroidCollider*>s_asteroidColliders;
    std::vector<BulletCollider*>s_bulletColliders;
    Circle m_collider;

};

