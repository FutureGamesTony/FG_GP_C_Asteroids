#pragma once
#include "ICollider.h"
#include <string>
#include <vector>
#include <cmath>
struct SDL_Rect;
class CollisionManager
{
public:
	bool CheckCollision(SDL_Rect A, SDL_Rect B);
    //Circle/Circle collision detector
    bool CheckCollision(Circle& A, Circle& B);

    //Circle/Box collision detector
    bool CheckCollision(Circle& A, SDL_Rect& B);

    bool CheckCollision(Circle& A, std::vector<SDL_Rect>& B);

    //Calculates distance squared between two points
    double DistanceSquared(int x1, int y1, int x2, int y2);
private:
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    double Distance(int x1, int y1, int x2, int y2);
};

