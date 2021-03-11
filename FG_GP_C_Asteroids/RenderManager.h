#pragma once
#include "IEntity.h"
#include "ISprite.h"
#include "ICollider.h"
#include <vector>
#include <iostream>
class Renderer;
class PlayerSprite;
class DrawWindow;
class AsteroidSprite;
class ISprite;
class SpriteManager;
class EntityManager;
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
class RenderManager
{
public:
	RenderManager(EntityManager* entityManager);
	~RenderManager();
	bool InitializeWidow();
	bool InitializeRenderer();
	bool InitializeSpriteManager();
	bool InistializeTexture(ISprite* sprite);
	void InitializeSprites();
	void UpdateWindow();
	void ShutDown();
	void WrapCoordinates(float inX, float inY, float &outX, float &outY);
	void DrawAsteroids(AsteroidSprite asteroid);
	void DrawSprites();
	void RenderColliders();
	SDL_Renderer* m_renderer = nullptr; // only render pointer, when used in other places, this should be passed in.
private:
	void SetSprite();

	int m_width = 800;
	int m_height = 600;
	int framecount = 0;
	int timerFPS = 0;
	int lastFrame = 0;
	int fps = 0;
	bool running = 0;
	bool fullscreen = 0;
	SDL_Window* m_window; // only window pointer, when used in other places, this should be passed in.
	SDL_Texture* m_texture; // only window pointer, when used in other places, this should be passed in.
	//SDL_Renderer* m_renderer = nullptr; // only render pointer, when used in other places, this should be passed in.
	DrawWindow* m_drawWindow = nullptr;
	ISprite* m_renderSprite = nullptr;
	SpriteManager* m_spriteManager = nullptr;
	std::vector<ISprite*> s_renderSprites; // Holds our sprites
	std::vector <ICollider*> s_colliders;
	Renderer* m_createRenderer = nullptr;
	EntityManager* m_entityManager = nullptr;
	const char* m_windowTitle = "Window Title"; //TODO: Destroy pointer array
};

