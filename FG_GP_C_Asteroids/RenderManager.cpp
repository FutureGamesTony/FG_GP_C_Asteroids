#include "RenderManager.h"
#include "DrawWindow.h"
RenderManager::RenderManager()
{
    m_drawWindow = new DrawWindow();
}

RenderManager::~RenderManager()
{
    delete m_drawWindow;
    m_drawWindow = nullptr;
}

bool RenderManager::InitializeWidow()
{
    //m_window = SDL_CreateWindow(m_windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, 0);
    //if(m_window == nullptr) return false;
    //m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    //if (m_renderer == nullptr) return false;
    //
     m_drawWindow->CreateWindow();
    return m_drawWindow != nullptr;
}

void RenderManager::UpdateWindow()
{
    m_drawWindow->UpdateWindow();
}

void RenderManager::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}
