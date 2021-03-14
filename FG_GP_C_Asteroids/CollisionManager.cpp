#include "CollisionManager.h"

#include "SDL.h"
CollisionManager::CollisionManager()
{
    bottomA = 0;
    bottomB = 0;
    leftA = 0;
    leftB = 0;
    rightA = 0;
    rightB = 0;
    topA = 0;
    topB = 0;
}
CollisionManager::~CollisionManager()
{
}
// https://lazyfoo.net/SDL_tutorials/lesson19/index.php
bool CollisionManager::CheckCollision(SDL_Rect A, SDL_Rect B)
{

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;

}

bool CollisionManager::CheckCollision(Circle& A, Circle& B)
{
    //If the distance between the centers of the circles is less than the sum of their radii
    if (Distance(A.x, A.y, B.x, B.y) < (A.r + B.r))
    {
        //The circles have collided
        return true;
    }

    //If not
    return false;
}

bool CollisionManager::CheckCollision(Circle& a, SDL_Rect& b)
{
    return false;
}

bool CollisionManager::CheckCollision(Circle& A, std::vector<SDL_Rect>& B)
{
    //Closest point on collision box
    int cX, cY;

    //Go through the B boxes
    for (int Bbox = 0; Bbox < B.size(); Bbox++)
    {
        //Find closest x offset
        if (A.x < B[Bbox].x)
        {
            cX = B[Bbox].x;
        }
        else if (A.x > B[Bbox].x + B[Bbox].w)
        {
            cX = B[Bbox].x + B[Bbox].w;
        }
        else
        {
            cX = A.x;
        }
        //Find closest y offset
        if (A.y < B[Bbox].y)
        {
            cY = B[Bbox].y;
        }
        else if (A.y > B[Bbox].y + B[Bbox].h)
        {
            cY = B[Bbox].y + B[Bbox].h;
        }
        else
        {
            cY = A.y;
        }
        //If the closest point is inside the circle
        if (Distance(A.x, A.y, cX, cY) < A.r)
        {
            //This box and the circle have collided
            return true;
        }
    }

    //If the shapes have not collided
    return false;
}

std::vector<ICollider*> CollisionManager::GetColliders()
{
    return s_colliders;
}

void CollisionManager::SetColliders(ICollider* collider)
{
    s_colliders.push_back(collider);
}



double CollisionManager::DistanceSquared(int x1, int y1, int x2, int y2)
{
    //Return the distance between the two points
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


double CollisionManager::Distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
