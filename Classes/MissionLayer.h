//
//  MissionLayer.h
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 25..
//
//

#ifndef __SecondPuzzleGame__MissionLayer__
#define __SecondPuzzleGame__MissionLayer__

#include "cocos2d.h"
#include "GameSprite.h"
#include "PlayerBall.h"
#include "Candy.h"
#include "LineContainer.h"
#include "MissionInfo.h"

class MissionLayer : public cocos2d::Layer {
protected:
    typedef std::vector<GameSprite*> GameSpriteArray;
    typedef std::vector<Candy*> CandyArray;
    typedef std::vector<CandyArray*> CandyArrayArray;
    bool bGameOver;
    bool bMissionLoaded;
    bool bMissionRunning;
    int score;
    float gravityFactor;
    float airResistanceFactor;
    int curNumOfBall;
    cocos2d::Vec2 ballStartPoint;
    cocos2d::Size screenSize;
    cocos2d::Label *scoreLabel;
    GameSpriteArray movingObjectArray;
    CandyArrayArray candyTypeArray;
    CandyArray candyArray;
    PlayerBall * ball;
    cocos2d::Vec2 tap;
    LineContainer *linecontainer;
    void SetGameOver();
    
    MissionInfo *info;
    
    
public:
    MissionLayer();
    ~MissionLayer();
    //static MissionLayer * createMissionLayer();
    
    bool LoadMission();
    void UnloadMission();
    void StartMission();
    void StopMission();
    void PauseMission(bool);
    
    virtual void update(float);
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
    
    void BuildInstance();
    void Reset();
    void Generate();
};

#endif /* defined(__SecondPuzzleGame__MissionLayer__) */
