#pragma once
#include "SDL_image.h" // debugging (new)
#include "IEntity.h"
#include "ICollider.h"
#include "DopeAssEngine.h"
#include "EngingConfig.h"
#include <vector>
class Player;
class PlayerSprite;
class DrawWindow;
class RenderManager;
class EntityManager;
class SpriteManager;
class InputManager;
class ISprite;
class AsteroidSprite;
class CollisionManager;
class Asteroid;
class AsteroidSprite;
class IEntity;
class ICollider;
struct SDL_Window;
struct SDL_Renderer;
class EngineConfig;
class DopeAssEngine
{
public:
	DopeAssEngine();
	~DopeAssEngine();
	bool InitEngine();
	bool UpdateEngine();
	void ShutDown();
	void SpawnAsteroids();
private:
	void InitializeRenderManager();
	void InitializeEntityManager();
	void InitializeEnteties(EngineConfig::EntityType entity);
	void InitializeSprites();
	void InitializeCollisionManager();
	void InitializeInput();
	void UpdatePlayerDebug();
	Position UpdatePlayerPosition(int x, int y, int rotation);
	int UpdatePlayerRotation(int rotation);
	int m_width = 800;
	int m_height = 600;
	int framecount = 0;
	int timerFPS = 0;
	int lastFrame = 0;
	int fps = 0;
	bool running = 0;
	bool fullscreen = 0;
	////Player
	IEntity* m_player = nullptr;
	ISprite* m_playerSprite = nullptr;
	//Asteroid
	Asteroid* m_asteroid = nullptr;
	ISprite* m_asteroidSprite = nullptr;
	RenderManager* m_renderManager = nullptr;
	DrawWindow* m_drawWindow = nullptr;
	EntityManager* m_entityManager = nullptr;
	InputManager* m_inputManager = nullptr;
	CollisionManager* m_collisionManager = nullptr;
	std::vector<IEntity*>m_entities;
	std::vector<ISprite*>m_sprites;
	std::vector<ICollider*>(m_colliders);

	int rotation = 0;
	int x = 0;
	int y = 0;
	EngineConfig::PlayerInput m_keyPressed;
	EngineConfig::EntityType entityType;
	Circle circle; 
	ICollider* collider; 
	ISprite* sprite; 
	Position position; 
	Size size;
	int playerRotation;
	EngineConfig::PlayerInput keyPressed;
	Position playerPosition;
	Movement playerMovement;
	double  radians = 180 / 3.14;
	int movementSpeed = 10;
	double moveX = 0.0;
	double moveY = 0.0;

};

