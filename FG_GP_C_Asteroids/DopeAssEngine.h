#pragma once
#include "SDL_image.h" // debugging (new)
#include "IEntity.h"
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
struct  SDL_Renderer;

class DopeAssEngine
{
public:
	DopeAssEngine();
	~DopeAssEngine();
	bool InitEngine();
	bool UpdateEngine();
	void ShutDown();

private:
	void InitializeRenderManager();
	void InitializePlayer();
	void InitializeAsteroids();
	void InitializeEnteties();
	void InitializeSpriteManager();
	void InitializeCollisionManager();
	void InitializeInput();
	int m_width = 800;
	int m_height = 600;
	int framecount = 0;
	int timerFPS = 0;
	int lastFrame = 0;
	int fps = 0;
	bool running = 0;
	bool fullscreen = 0;
	////Player
	Player* m_player = nullptr;
	PlayerSprite* m_playerSprite = nullptr;
	//Asteroid
	Asteroid* m_asteroid = nullptr;
	AsteroidSprite* m_asteroidSprite = nullptr;
	RenderManager* m_renderManager = nullptr;
	DrawWindow* m_drawWindow = nullptr;
	EntityManager* m_entityManager = nullptr;
	InputManager* m_inputManager = nullptr;
	SpriteManager* m_spriteManager = nullptr;
	CollisionManager* m_collisionManager = nullptr;
	std::vector<IEntity*>(m_entities);
	std::vector<ISprite*>(m_sprites);
};

