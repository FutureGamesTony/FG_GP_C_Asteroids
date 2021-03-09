#pragma once
#include "IEntity.h"
#include "SDL.h"
#include "SDL_image.h"
class PlayerSprite;
static class Player : public IEntity
{
private:
//private stuff
public:
	Player(); // constructor play-time ship
	Player(int extraLifes) {}; //constructor for extra lifes
	~Player();
		/////////
		bool isDead = false;
		Entity_Type playerEntity = Entity_Type::Player_Entity;
		void Reset();
		void ApplyLeftRotation();
		void ApplyRightRotation();
		void ApplyAcceleration();
		void Explode();
		void FireWeapon();
		void CreateEntity(Entity_Type entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags,
			ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput) override;
		void Update() override;
		Size SetSize() override;
		Position SetPosition() override;
		Movement SetMovementInput() override;
		void UpdateMovement() override;
		ISprite* GetSprite() override;
		
		
		PlayerSprite* m_playerSprite;
		/////////
};

