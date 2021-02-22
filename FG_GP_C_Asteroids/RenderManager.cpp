#include "RenderManager.h"

RenderManager::RenderManager()
{

}

RenderManager::~RenderManager()
{

}

bool RenderManager::InitializeWidow()
{
    m_window = SDL_CreateWindow(m_windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, 0);
    if(m_window == nullptr) return false;
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    if (m_renderer == nullptr) return false;
    
    return true;
}

void RenderManager::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}
