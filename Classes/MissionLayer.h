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

class MissionInfo {
public:
    typedef struct spriteInfo
    {
        int type;
        float coord_x;
        float coord_y;
    } GameSpriteInfo;
protected:
    int targetListSize;
    GameSpriteInfo * targetList;
public:
    MissionInfo(int _size)
    {
        if(_size < 0)
        {
            _size = 0;
        }
        targetListSize =  _size;
        targetList = new GameSpriteInfo[targetListSize];
    }
    ~MissionInfo()
    {
        delete [] targetList;
    }
    GameSpriteInfo * GetGameSpriteInfo(int idx) {
        if(idx<0 || idx>=targetListSize) {
            return NULL;
        }
        return &targetList[idx];
    }
    int GetSize() {
        return targetListSize;
    }
};

class MissionLayer : public cocos2d::Layer {
protected:
    bool missionLoaded;
    int score;
    cocos2d::Size screenSize;
    cocos2d::Label *scoreLabel;
    std::vector<GameSprite*> movingObjectArray;
    std::vector<Candy*> candyArray;
    PlayerBall * ball;
    void ClearMission();
    cocos2d::Vec2 tap;

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
