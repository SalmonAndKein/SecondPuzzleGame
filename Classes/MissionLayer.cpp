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
    //screenSize = cocos2d::Director::getInstance()->getVisibleSize();
    //ball = PlayerBall::createWithType(0);
    //ball->setPosition(cocos2d::Vec2(screenSize.width*0.5f,screenSize.height*0.2f));
    //this->addChild(ball);
    
    if(missionLoaded || info->GetSize() < 0)
        return false;
    
    for(int i=0; i<info->GetSize(); i++) {
        auto candyData = info->GetGameSpriteInfo(i);
        float candy_position_x = candyData->coord_x;
        float candy_position_y = candyData->coord_y;
        //int candyType = candyData->type;
        //auto curCandy = Candy::createWithTypeNumber(candyType);
        auto curCandy = new Candy();
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