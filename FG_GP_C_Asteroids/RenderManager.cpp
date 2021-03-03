#include "RenderManager.h"
#include "DrawWindow.h"
#include "Asteroid.h"
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

    for (auto& a : Asteroid::asteroids)
    {
        a.xPos += a.velocityX * m_drawWindow->timerFPS;
        a.yPos += a.velocityY * m_drawWindow->timerFPS;

        for (int x = 0; x < a.size; x++)
        {
            for (int y = 0; y < a.size; y++)
            {
                //draw rectangle asteroid here
            }
        }
    }
}

void RenderManager::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}
void RenderManager::WrapCoordinates(float inX, float inY, float &outX, float &outY)
{
    outX = inX;
    outY = inY;
    if (inX < 0.0f) // if input is less than 0, adjust: input + screenWidth
    {
        outX = inX + (float)m_width;
    }
    if (inX >= (float)m_width) //if input is greater that screenwidth, adjust: input - screenwidth
    {
        outX = inX - (float)m_width;
    }
    //same with Y
    if (inY < 0.0f)
    {
        outX = inY + (float)m_height;
    }
    if (inY >= (float)m_height)
    {
        outX = inY - (float)m_height;
    }
}
