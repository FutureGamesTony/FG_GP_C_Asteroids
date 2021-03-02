#include "RenderManager.h"
#include "DrawWindow.h"
RenderManager::RenderManager()
{
    m_drawWindow = new DrawWindow(m_window, m_renderer);
    
}

RenderManager::~RenderManager()
{
    delete m_drawWindow;
    m_drawWindow = nullptr;
}

bool RenderManager::InitializeWidow()
{
    m_window = m_drawWindow->CreateWindow(m_window);
    m_renderer = m_drawWindow->CreateRenderer(m_window, m_renderer);
    return m_drawWindow != nullptr;
}

void RenderManager::UpdateWindow()
{
    m_drawWindow->UpdateWindow(m_renderer);
}

void RenderManager::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}
