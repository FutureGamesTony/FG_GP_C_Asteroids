#pragma once
struct SDL_Renderer;
struct SDL_Window;
class Renderer
{
public:
	Renderer();
	~Renderer();
	SDL_Renderer* CreateRenderer(SDL_Window* window, SDL_Renderer* renderer);
private:
};

