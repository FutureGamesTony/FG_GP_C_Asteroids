#pragma once
#include "ICollider.h"

class PlayerCollider : public ICollider
{
public:// LazyFoo 
    //Initializes the variables
	void CreateCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider, Circle circleCollider) override;

    //Takes key presses and adjusts the square's velocity
    void handle_input();

    //Moves the square
    void move();

    //Shows the square on the screen
    void show();
	Size GetSize();
private:
	Size SetSize();
    SDL_Rect box;

    //The velocity of the square
    int xVel, yVel;



  

};

