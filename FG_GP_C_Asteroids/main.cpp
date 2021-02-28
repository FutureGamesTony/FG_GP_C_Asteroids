#include "SDL.h"
#include "iostream"
#include "Keyboard.h"

#define WIDTH 1280
#define HEIGHT 720

SDL_Renderer* renderer;
SDL_Window* window;

int framecount;
int timerFPS;
int lastFrame;
int fps;
Keyboard* key = nullptr;
bool running;
bool fullscreen;

void Input()
{
	//SDL_Event e;
	//while (SDL_PollEvent(&e))
	//{
	//	if (e.type == SDL_QUIT)
	//	{
	//		running = false;
	//	}
	//	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	//	{
	//		if (keystates[SDL_SCANCODE_ESCAPE]) { running = false; }
	//		if (keystates[SDL_SCANCODE_F11]) { fullscreen = !fullscreen; }
	//	}
	//}
	key->GetKeyDown();

}

void Update()
{
	if (fullscreen) 
	{
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	}
	if (!fullscreen)
	{
		SDL_SetWindowFullscreen(window, 0);
	}
}

void Draw()
{
	SDL_SetRenderDrawColor(renderer, 49, 70, 83, 255); // set color to blueish-grey
	SDL_Rect rect; //creates a rectangle
	rect.x = rect.y = 0;

	rect.w = WIDTH;
	rect.h = HEIGHT;
	SDL_RenderFillRect(renderer, &rect);

	framecount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if(timerFPS<(1000/60))
	{
		SDL_Delay((1000 / 60) - timerFPS);
	}

	SDL_RenderPresent(renderer);
}

int main(int argc, char** argv) 
{
	running = true;
	fullscreen = 0;
	static int lastTime;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl; // initializing sdl
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;
	SDL_SetWindowTitle(window, "Asteroids Dope-ass version ");
	SDL_ShowCursor(0); // hides cursor in window
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2"); // render pixels better (anisotropic filtering)
	while (running)
	{
		lastFrame = SDL_GetTicks();
		if(lastFrame >= (lastFrame + 1000)) 
		{
			lastTime = lastFrame;
			fps = framecount;
			framecount = 0;
		}
		//std::cout << fps << std::endl;

		Update();
		Input();
		Draw();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}