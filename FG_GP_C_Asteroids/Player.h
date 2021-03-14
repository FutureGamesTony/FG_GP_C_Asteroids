#pragma once
#include "IEntity.h"
#include "SDL.h"
#include "SDL_image.h"
class PlayerSprite;
class PlayerCollider;
class EntityType;
static class Player : public IEntity
{

public:
	Player(); // constructor play-time ship
	Player(int extraLifes); //constructor for extra lifes
	~Player();
		/////////
		bool isDead = false;
		EngineConfig::EntityType playerEntity;
		void Reset();
		void ApplyLeftRotation();
		void ApplyRightRotation();
		void ApplyAcceleration();
		void Explode();
		void FireWeapon();
		void CreateEntity(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags,
			ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput) override;
		void Update() override;
		Size SetSize() override;
		Position SetPosition() override;
		void UpdateMovement(float moveX, float moveY, float xPos, float yPos) override;
		ISprite* GetSprite() override;
		EngineConfig::EntityType GetEntityType() override;
		SDL_Rect* m_collider;
		void CreateSprite(SDL_Renderer* renderer) override;
		ISprite* m_playerSprite;
		ICollider* m_playerCollider;
		Movement SetMovementInput(EngineConfig::PlayerInput moveCommand) override;

		ICollider* GetCollider() override;
		/////////
		Circle circle;
		Position position;
		Movement movement;
		Size size;
private:
		void CreatePlayer(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex,
			Uint32 renderFlags, ISprite* playerSprite, ICollider* playerCollider,
			SDL_Surface* surface, char* spriteFilePath, Circle circle, Position position, Movement movement);
};

