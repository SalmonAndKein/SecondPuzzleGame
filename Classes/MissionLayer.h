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
    bool bGameOver;
    bool missionLoaded;
    int score;
    float gravity;
    float airResistance;
    int numOfBall;
    cocos2d::Vec2 ballStartPoint;
    cocos2d::Size screenSize;
    cocos2d::Label *scoreLabel;
    std::vector<GameSprite*> movingObjectArray;
    std::vector<Candy*> candyArray;
    PlayerBall * ball;
    cocos2d::Vec2 tap;
    LineContainer *linecontainer;
    void ClearMission();
   
public:
    MissionLayer();
    ~MissionLayer();
    //static MissionLayer * createMissionLayer();
    bool LoadMission(MissionInfo*);
    virtual void update(float);
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
};

#endif /* defined(__SecondPuzzleGame__MissionLayer__) */
