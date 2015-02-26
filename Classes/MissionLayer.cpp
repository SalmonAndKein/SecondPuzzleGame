//
//  MissionLayer.cpp
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 25..
//
//

#include "MissionLayer.h"

MissionLayer::MissionLayer() {
    missionLoaded = false;
}
MissionLayer::~MissionLayer() {
    
}
void MissionLayer::ClearMission() {
    candyArray.empty();
    this->removeAllChildren();
    missionLoaded = false;
}
bool MissionLayer::LoadMission(MissionInfo * info) {
    if(missionLoaded || info->GetSize() < 0)
        return false;
    
    for(int i=0; i<info->GetSize(); i++) {
        auto candyData = info->GetGameSpriteInfo(i);
        float candy_position_x = candyData->coord_x;
        float candy_position_y = candyData->coord_y;
        int candyType = candyData->type;
        auto curCandy = Candy::createWithTypeNumber(candyType);
        curCandy->setPosition(cocos2d::Vec2(candy_position_x, candy_position_y));
        curCandy->setGravity(false);
        candyArray.push_back(curCandy);
        this->addChild(curCandy);
        curCandy->retain();
    }
    missionLoaded = true;
    return true;
}
void MissionLayer::update() {
    
}

bool MissionLayer::onTouchBagan(cocos2d::Touch *pTouches)
{
    if (pTouches)
    {
        float dx = ball->getPosition().x - pTouches->getLocation().x;
        float dy = ball->getPosition().y - pTouches->getLocation().y;
        
        if (dx*dx + dy*dy <= pow(ball->Radius(), 2))
        {
            tap = pTouches->getLocation();
            return true;
        }
    }
    return false;
}

void MissionLayer::onTouchMoved(cocos2d::Touch *pTouches)
{
}
void MissionLayer::onTouchEnded(cocos2d::Touch *pTouches)
{
    if (pTouches)
    {
        float dx = ball->getPosition().x - pTouches->getLocation().x;
        float dy = ball->getPosition().y - pTouches->getLocation().y;
        
        if (dx*dx + dy*dy <= pow(ball->Radius(), 2))
        {
            cocos2d::Vec2 pivot = pTouches->getLocation();
            ball->setMoveVector(cocos2d::ccpSub(pivot, tap));
        }
    }
}