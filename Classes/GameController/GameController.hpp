//
//  GameController.hpp
//  SpaceInvaders
//
//  Created by roko on 12/14/16.
//
//

#ifndef GameController_hpp
#define GameController_hpp

#include "CSNodeIncludes.hpp"
#include "Helper.hpp"
#include "PhysicsDefinitions.hpp"

#define SCREEN_RECT GameController::getInstance().getScreenRect()
#define GAME_CONTROLLER GameController::getInstance()
#define CUR_LEVEL GameController::getInstance().getLevel()

class Level;

class GameController:
public AppDelegateProtocol
{
public:
    static GameController & getInstance();
    
    GameController(GameController const&) = delete;
    GameController(GameController&&) = delete;
    GameController& operator=(GameController const&) = delete;
    GameController& operator=(GameController &&) = delete;
    
protected:
    GameController();
    ~GameController();
    
private:
    struct Impl;
    std::unique_ptr<Impl> m_pImpl;
    
public:
    void runStartMenu();
    void startNewGame();
    void pauseGame();
    void resumeGame();
    bool isGamePaused() const;
    void exitToMenu();
    void addGameObject(cocos2d::Node * pNode);
    void removeGameObject(cocos2d::Node * pNode);
    Level const * const getLevel() const;
    
#pragma mark AppDelegateProtocol
    void applicationWillResignActive() override;
};

#endif /* GameController_hpp */
