#pragma once
#include "IEntity.h"

#include <iostream>
//#include "sEntity.h"
class AsteroidCollider;
class ICollider;
class ISprite;
class AsteroidSprite;
class Asteroid : public IEntity 
{
public:
	Asteroid(const char *path, SDL_Renderer* renderer);
	~Asteroid();

	void Split();
	void Explode();
	void Advance();
	int getXpos();
	int getYpos();
	int getXvelocity();
	int getYvelocity();
	int getSize();
	void CreateEntity(Entity_Type entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags,
		ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput) override;
	void UpdateMovement() override;

	ICollider* GetCollider() override;
	ISprite* GetSprite() override;
	Size SetSize() override;
	Position SetPosition() override;
	Movement SetMovementInput(std::vector<Keyboard::PlayerInput> inputList) override;
	void Update() override;
	SDL_Rect* collider = nullptr;
	Circle circleCollider;
	int velocityX;
	int velocityY;
private:
	Entity_Type m_asteroid_Entity = Entity_Type::Asteroid_Entity;
	void CreateAsteroid(Entity_Type &entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex,
						Uint32 renderFlags, ISprite* asteroidSprite, ICollider* asteroidCollider, 
						SDL_Surface* surface, char* spriteFilePath, Circle circle, Position position, Movement movement);
	std::string filePath = "assets/AsteroidLarge.png";
	AsteroidSprite* m_asteroidSprite;
	AsteroidCollider* m_asteroidCollider;
	Position position;
	Movement movement;
	Size size;
};

