#pragma once
class SDL_Renderer;
class PlayerSprite
{
public:
	PlayerSprite(SDL_Renderer* renderer);
	~PlayerSprite();


private:
	void DrawPlayer(SDL_Renderer* drawPlayer);
};

