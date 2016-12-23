//
//  GameController.cpp
//  SpaceInvaders
//
//  Created by roko on 12/14/16.
//
//

#include "GameController.hpp"
#include "MakeUnique.h"
#include "PauseLayer.hpp"
#include "GameScene.hpp"
#include "StartScene.hpp"
#include "HealthComponent.hpp"
#include "VelocityComponent.hpp"
#include "Level.hpp"
#include "BinMacro.h"
#include "GameOverLayer.hpp"
#include "ComponentDefinitions.hpp"
#include "DamageComponent.hpp"


USING_NS_CC;

using namespace cocos2d::ui;

struct GameController::Impl
{
    Impl();
    bool m_isPaused;
    bool m_isGameOver;
    PauseLayer * m_pPauseLayer;
    GameScene * m_pGameScene;
    Level m_level;
    
    void runStartMenu();
    void startNewGame();
    void pauseGame();
    void resumeGame();
    bool isGamePaused() const;
    void exitToMenu();
    
    void addGameObject(cocos2d::Node * pNode);
    void removeGameObject(cocos2d::Node * pNode);
    
    Level const * const getLevel() const;
    
private:
    static Scene * createSceneWithNode(Node * pNode);
    void resetGameVariables();
    void initGame();
    
private:
    void freezeGame();
    void unfreezeGame();
    
public:
    void gameLost();
    void gameWon();
    
};

#pragma mark Impl methods

GameController::Impl::Impl():
m_pPauseLayer(nullptr),
m_pGameScene(nullptr),
m_isPaused(false),
m_isGameOver(false)
{
    
}

void GameController::Impl::runStartMenu()
{
    auto pLayer = StartScene::createDefault();
    auto pScene = createSceneWithNode(pLayer);
    Director::getInstance()->runWithScene(pScene);
}

void GameController::Impl::startNewGame()
{
    initGame();
    auto pScene = createSceneWithNode(m_pGameScene);
    Director::getInstance()->replaceScene(pScene);
}

void GameController::Impl::pauseGame()
{
    if (!m_isPaused && !m_isGameOver) {
        if (m_pPauseLayer && !(m_pPauseLayer->getParent())) {
            m_pGameScene->addChild(m_pPauseLayer, m_level.kPauseLayerZ);
        }
        freezeGame();
        m_isPaused = true;
    }
}

void GameController::Impl::resumeGame()
{
    if (m_isPaused) {
        if (m_pPauseLayer && m_pPauseLayer->getParent()) {
            m_pPauseLayer->removeFromParent();
        }
        unfreezeGame();
        m_isPaused = false;
    }
}

bool GameController::Impl::isGamePaused() const
{
    return m_isPaused;
}

void GameController::Impl::exitToMenu()
{
    auto pLayer = StartScene::createDefault();
    auto pScene = createSceneWithNode(pLayer);
    Director::getInstance()->replaceScene(pScene);
}

void GameController::Impl::addGameObject(cocos2d::Node * pNode)
{
    m_pGameScene->getObjectPanel()->addChild(pNode);
}

void GameController::Impl::removeGameObject(cocos2d::Node * pNode)
{
    pNode->removeFromParent();
}

Level const * const GameController::Impl::getLevel() const
{
    return &m_level;
}

Scene * GameController::Impl::createSceneWithNode(Node * pNode)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // add layer as a child to scene
    scene->addChild(pNode);
    
    // return the scene
    return scene;
}

void GameController::Impl::resetGameVariables()
{
    m_isPaused = false;
    m_isGameOver = false;
    
    if (m_pPauseLayer) {
        m_pPauseLayer->release();
        m_pPauseLayer = nullptr;
    }
    
    m_pGameScene = nullptr;
}

void GameController::Impl::initGame()
{
    resetGameVariables();
    
    m_level = Level();
    
    m_pPauseLayer = PauseLayer::createDefault();
    m_pPauseLayer->retain();
    
    m_pGameScene = GameScene::createDefault();
}

void GameController::Impl::freezeGame()
{
    m_pGameScene->getObjectPanel()->enumerateChildren("//[[:alnum:]]*", [this](Node * pNode) -> bool {
        pNode->pause();
        return false;
    });
}

void GameController::Impl::unfreezeGame()
{
    m_pGameScene->getObjectPanel()->enumerateChildren("//[[:alnum:]]*", [this](Node * pNode) -> bool {
        pNode->resume();
        return false;
    });
}

void GameController::Impl::gameLost()
{
    if (!m_isGameOver && !m_isPaused) {
        m_isGameOver = true;
        freezeGame();
        
        auto gameOverLayer = GameOverLayer::createDefault();
        gameOverLayer->getFinishText()->setString("YOU LOSE!");
        m_pGameScene->addChild(gameOverLayer, m_level.kGameOverZ);
    }
}

void GameController::Impl::gameWon()
{
    if (!m_isGameOver && !m_isPaused) {
        m_isGameOver = true;
        freezeGame();
        
        auto gameOverLayer = GameOverLayer::createDefault();
        gameOverLayer->getFinishText()->setString("YOU WON!");
        m_pGameScene->addChild(gameOverLayer, m_level.kGameOverZ);
    }
}

#pragma mark GameController methods

GameController & GameController::getInstance()
{
    static GameController s_instance;
    return s_instance;
}

GameController::GameController():
m_pImpl(std::make_unique<Impl>())
{
    
}

GameController::~GameController()
{
    
}

void GameController::runStartMenu()
{
    m_pImpl->runStartMenu();
}

void GameController::startNewGame()
{
    m_pImpl->startNewGame();
}

void GameController::pauseGame()
{
    m_pImpl->pauseGame();
}

void GameController::resumeGame()
{
    m_pImpl->resumeGame();
}

bool GameController::isGamePaused() const
{
    return m_pImpl->isGamePaused();
}

void GameController::exitToMenu()
{
    m_pImpl->exitToMenu();
}

void GameController::addGameObject(cocos2d::Node * pNode)
{
    m_pImpl->addGameObject(pNode);
}

void GameController::removeGameObject(cocos2d::Node * pNode)
{
    m_pImpl->removeGameObject(pNode);
}

Level const * const GameController::getLevel() const
{
    return m_pImpl->getLevel();
}

#pragma mark AppDelegateProtocol
void GameController::applicationWillResignActive()
{
    CCLOG("applicationWillResignActive");
    this->pauseGame();
}
