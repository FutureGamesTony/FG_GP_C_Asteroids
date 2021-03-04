#include "DopeAssEngine.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "DrawWindow.h"
#include "Player.h"
DopeAssEngine::DopeAssEngine()
{
    m_drawWindow = new DrawWindow();
    m_renderManager = new RenderManager();
}

DopeAssEngine::~DopeAssEngine()
{
    delete m_player;
    m_player = nullptr;
}

bool DopeAssEngine::InitEngine()
{
    return m_drawWindow != nullptr && m_renderManager != nullptr;
}

bool DopeAssEngine::UpdateEngine()
{
    m_renderManager->UpdateWindow();
    return true;
}
//void DopeAssEngine::InitializeRenderManager()
//{
//    m_renderManager = new RenderManager();
//}

void DopeAssEngine::InitializePlayer()
{
    m_player = new Player();
}

void DopeAssEngine::InitializeInput()
{
    m_inputManager = new InputManager();
}
void DopeAssEngine::InitializeAsteroids()
{

}
void DopeAssEngine::ShutDown()
{
}
