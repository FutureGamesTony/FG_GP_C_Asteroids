#pragma once
struct SDL_Window;
struct SDL_Texture;
class  ISprite { 
public: // By creating an abstract class, we can ensure all functions that inherits this class has everything needed, or it will give compilation error
		// so if more or less things are needed, this is the first place to adjust. 
	virtual int CreateSprite(SDL_Window* window, SDL_Texture* texture, int pixelFormat, int textureAccess, int width, int height) = 0;
	virtual void ModifyRects() = 0;

};