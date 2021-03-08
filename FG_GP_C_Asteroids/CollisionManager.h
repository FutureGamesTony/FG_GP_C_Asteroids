#pragma once
struct SDL_Rect;
class CollisionManager
{
public:
	bool CheckCollision(SDL_Rect a, SDL_Rect b);
private:
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

};

