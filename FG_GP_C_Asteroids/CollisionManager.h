#pragma once
#include "ICollider.h"
#include "EngingConfig.h"
#include "IEntity.h"
#include <string>
#include <vector>
#include <cmath>
struct SDL_Rect;
class EntityType;
class CollisionManager
{
public:

    CollisionManager();
    ~CollisionManager();
	bool CheckCollision(SDL_Rect A, SDL_Rect B);
    //Circle/Circle collision detector
    bool CheckCollision(Circle& A, Circle& B);

    //Circle/Box collision detector
    bool CheckCollision(Circle& A, SDL_Rect& B);

    bool CheckCollision(Circle& A, std::vector<SDL_Rect>& B);
    std::vector<ICollider*>GetColliders();
    void SetColliders(ICollider* collider);
    //Calculates distance squared between two points
    double DistanceSquared(int x1, int y1, int x2, int y2);
private:
    std::vector<EngineConfig::EntityType> s_entityTypes;
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    double Distance(int x1, int y1, int x2, int y2);

    std::vector<ICollider*> s_colliders;
};

