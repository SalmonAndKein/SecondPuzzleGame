//
//  MissionLayer.cpp
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 25..
//
//

#include "MissionLayer.h"
/*
int gravity;
int score;
cocos2d::Size screanSize;
cocos2d::Label *scoreLabel;
std::vector<GameSprite*> candyArray;
GameSprite * ball;
public:
MissionLayer();
~MissionLayer();
//static MissionLayer * createMissionLayer();
bool LoadMission(MissionInfo&);
void update();
*/

MissionLayer::MissionLayer() {
    
}
MissionLayer::~MissionLayer() {
    
}
bool MissionLayer::LoadMission(MissionInfo * info) {
    screenSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    
    ball = PlayerBall::createWithType(0);
    ball->setPosition(cocos2d::Vec2(screenSize.width*0.5f,screenSize.height*0.2f));
    this->addChild(ball);
    return true;
}
void MissionLayer::update() {
    
}