#include "DopeAssEngine.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "DrawWindow.h"
#include "Player.h"
DopeAssEngine::DopeAssEngine()
{

}

DopeAssEngine::~DopeAssEngine()
{
    delete m_player;
    m_player = nullptr;
    delete m_inputManager;
    m_inputManager = nullptr;
    delete m_renderManager;
    m_renderManager = nullptr;
}

bool DopeAssEngine::InitEngine()
{
    m_renderManager = new RenderManager();
    m_inputManager = new InputManager();
    return m_renderManager != nullptr && m_inputManager != nullptr;
}

bool DopeAssEngine::UpdateEngine()
{
    m_renderManager->UpdateWindow();
    return true;
}


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
