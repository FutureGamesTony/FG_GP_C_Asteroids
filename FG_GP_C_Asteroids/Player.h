#pragma once
#include "IEntity.h"
#include "SDL.h"
#include "SDL_image.h"
#include "EngingConfig.h"
class PlayerSprite;
class PlayerCollider;
class EntityType;
static class Player : public IEntity
{

public:
	Player(EngineConfig::EntityType entityType, ISprite* playerSprite, ICollider* playerCollider, Position position, double rotation); // constructor play-time ship
	Player(int extraLifes); //constructor for extra lifes
	~Player();
		/////////
		bool isDead = false;
		EngineConfig::EntityType playerEntity;
		void Reset();
		void Explode();
		void FireWeapon();
		void CreateEntity(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags,
			ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput) override;
		void Update() override;
		Size SetSize() override;
		Position GetPosition() override;
		Position SetPosition() override;
		double GetRotation() override;
		ISprite* GetSprite() override;
		EngineConfig::EntityType GetEntityType() override;
		SDL_Rect* m_collider;
		void CreateSprite(SDL_Renderer* renderer) override;
		ISprite* m_playerSprite;
		ICollider* m_playerCollider;
		Movement SetMovementInput(EngineConfig::PlayerInput moveCommand) override;

		ICollider* GetCollider() override;

		Size size;
private:
		void CreatePlayer(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex,
			Uint32 renderFlags, ISprite* playerSprite, ICollider* playerCollider,
			SDL_Surface* surface, char* spriteFilePath, Circle circle, Position position, Movement movement);
		Position SetPlayerPosition();
		int SetPlayerRotation();
		int playerRotation;
		EngineConfig::PlayerInput keyPressed;
		Position playerPosition;
		Movement playerMovement;
		double  radians = 180 / 3.14;
		int movementSpeed = 3;
		int m_playerRotation = 0;
};

