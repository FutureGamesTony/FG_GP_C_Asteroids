#pragma once

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
class PlayerSprite;
class ISprite;
class DrawWindow
{
public:
	DrawWindow();
	~DrawWindow();
	SDL_Window* CreateWindow(SDL_Window* window);

	//SDL_Renderer* CreateRenderer(SDL_Window* window, SDL_Renderer* renderer);
private:
};