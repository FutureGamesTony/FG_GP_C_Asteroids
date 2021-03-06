#pragma once
class Renderer;
class PlayerSprite;
class DrawWindow;
class Asteroid;
struct SDL_Window;
struct SDL_Renderer;
class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	bool InitializeWidow();
	bool InitializeRenderer();
	void UpdateWindow();
	void ShutDown();
	void WrapCoordinates(float inX, float inY, float &outX, float &outY);
	void DrawAsteroids(Asteroid asteroid);
	SDL_Renderer* m_renderer = nullptr; // only render pointer, when used in other places, this should be passed in.
private:
	int m_width = 800;
	int m_height = 600;
	int framecount = 0;
	int timerFPS = 0;
	int lastFrame = 0;
	int fps = 0;
	bool running = 0;
	bool fullscreen = 0;
	SDL_Window* m_window; // only window pointer, when used in other places, this should be passed in.
	//SDL_Renderer* m_renderer = nullptr; // only render pointer, when used in other places, this should be passed in.
	DrawWindow* m_drawWindow = nullptr;
	PlayerSprite* m_playerSprite = nullptr;
	Renderer* m_createRenderer = nullptr;
	const char* m_windowTitle = "Window Title"; //TODO: Destroy pointer array
};

