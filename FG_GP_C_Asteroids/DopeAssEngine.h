#pragma once
#include "SDL_image.h" // debugging (new)
class Player;
class PlayerSprite;
class DrawWindow;
class RenderManager;
class InputManager;
//struct SDL_Window;
//struct  SDL_Renderer;
class DopeAssEngine
{
public:
	DopeAssEngine();
	~DopeAssEngine();
	bool InitEngine();
	bool UpdateEngine();
	void ShutDown();
	SDL_Texture* playerTex; //(new)
private:
	void InitializeRenderManager();
	void InitializePlayer();
	void InitializeAsteroids();
	void InitializeInput();
	int m_width = 800;
	int m_height = 600;
	int framecount = 0;
	int timerFPS = 0;
	int lastFrame = 0;
	int fps = 0;
	bool running = 0;
	bool fullscreen = 0;
	RenderManager* m_renderManager = nullptr;
	DrawWindow* m_drawWindow = nullptr;
	Player* m_player = nullptr;
	InputManager* m_inputManager = nullptr;
	//DrawWindow* m_drawWindow = nullptr;
	PlayerSprite* m_playerSprite = nullptr;
};

