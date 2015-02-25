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

class MissionInfo {
public:
    int num;
    MissionInfo(int _num = 2)
    {
        num =  _num;
        
    }
    ~MissionInfo()
    {
        
    }
};

class MissionLayer : public cocos2d::Layer {
protected:
    int gravity;
    int score;
    cocos2d::Size screenSize;
    cocos2d::Label *scoreLabel;
    std::vector<GameSprite*> candyArray;
    PlayerBall * ball;
public:
    MissionLayer();
    ~MissionLayer();
    //static MissionLayer * createMissionLayer();
    bool LoadMission(MissionInfo*);
    void update();
};

#endif /* defined(__SecondPuzzleGame__MissionLayer__) */
