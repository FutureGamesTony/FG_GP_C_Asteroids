#pragma once
struct SDL_Renderer;
class PlayerSprite
{
public:
	PlayerSprite();
	~PlayerSprite();

	void DrawPlayer(SDL_Renderer* drawPlayer);
private:
};

