#pragma once
#include "IEntity.h"
#include "SDL.h"
#include "SDL_image.h"
class PlayerSprite;
class PlayerCollider;
static class Player : public IEntity
{
private:
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
		void UpdateMovement(float X, float Y) override;
		ISprite* GetSprite() override;
		SDL_Rect* m_collider;
		void CreateSprite(SDL_Renderer* renderer) override;
		PlayerSprite* m_playerSprite;
		PlayerCollider* m_playerCollider;
		// Inherited via IEntity
		ICollider* GetCollider() override;
		/////////
		Circle circle;
		Position position;
		Movement movement;
		Size size;

		// Inherited via IEntity
		Movement SetMovementInput(Keyboard::PlayerInput moveCommand) override;
};

