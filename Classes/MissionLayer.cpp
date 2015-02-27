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
    movingObjectArray.empty();
    candyArray.empty();
    this->removeAllChildren();
    missionLoaded = false;
}
bool MissionLayer::LoadMission(MissionInfo * info) {
    
    screenSize = cocos2d::Director::getInstance()->getWinSize();
    if(missionLoaded || info->GetSize() < 0)
        return false;
    
    ball = PlayerBall::createWithType(0);
    ball->setIsMoving(false);
    ball->setPosition(100,200);
    ball->setMoveVector(cocos2d::Vec2(0,0));
    movingObjectArray.push_back(ball);
    this->addChild(ball);
    
    for(int i=0; i<info->GetSize(); i++) {
        auto candyData = info->GetGameSpriteInfo(i);
        float candy_position_x = candyData->coord_x;
        float candy_position_y = candyData->coord_y;
        int candyType = candyData->type;
        auto curCandy = Candy::createWithTypeNumber(candyType);
        curCandy->setPosition(cocos2d::Vec2(candy_position_x, candy_position_y));
        curCandy->setIsMoving(false);
        curCandy->setMoveVector(cocos2d::Vec2(0,0));
        candyArray.push_back(curCandy);
        movingObjectArray.push_back(curCandy);
        this->addChild(curCandy);
        curCandy->retain();
    }

    missionLoaded = true;
    return true;
}
void MissionLayer::update(float dt) {
    cocos2d::Vec2 vec = ball->getMoveVector();
    if (ball->getPosition().y>=screenSize.height || ball->getPosition().y<=0)
    {
        vec.y = -vec.y;
    }
    if (ball->getPosition().x>=screenSize.width || ball->getPosition().x<=0)
    {
        vec.x = -vec.x;
    }
    
    ball->setMoveVector(vec * 0.98);

    for(int i=0; i<movingObjectArray.size(); i++)
    {
        //움직임이 적용되는 대상에게만 공식 대입
        if(movingObjectArray[i]->getIsMoving())
        {
            //중력 0.1 적용
            cocos2d::Vec2 curMoveVec = movingObjectArray[i]->getMoveVector();
            curMoveVec.y -= 0.98;
            
            //만약 벡터의 절대값이 0.001보다 작을경우 값을 0으로 변경
            if(std::abs(curMoveVec.x) < 0.001)
                curMoveVec.x = 0;
            if(std::abs(curMoveVec.y) < 0.001)
                curMoveVec.y = 0;
            
            //수정된 값에 따라 벡터값 재적용 후 이동
            movingObjectArray[i]->setMoveVector(curMoveVec);
            movingObjectArray[i]->Move();
        }
        if(movingObjectArray[i]->getPosition().y <= 0) {
            movingObjectArray[i]->setIsMoving(false);
            if (movingObjectArray[i] == ball)
            {
                movingObjectArray[i]->setPosition(cocos2d::Vec2(screenSize.width*0.5,screenSize.height*0.1));
            }
            
        }
    }
    for(int i=0; i<candyArray.size(); i++) {
        float diff_x = std::abs(candyArray[i]->getPosition().x - ball->getPosition().x);
        float diff_y = std::abs(candyArray[i]->getPosition().y - ball->getPosition().y);
        float sumOfRadi = candyArray[i]->Radius() + ball->Radius();
        if (pow(diff_x, 2) + pow(diff_y, 2) <= pow(ball->Radius() + candyArray[i]->Radius(), 2))
        {
            candyArray[i]->setIsMoving(true);
        }
        
       
    }
}

bool MissionLayer::onTouchBegan(cocos2d::Touch *pTouches,cocos2d::Event *event)
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

void MissionLayer::onTouchMoved(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
    
}
void MissionLayer::onTouchEnded(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
    
    if (pTouches)
    {
    
        cocos2d::Vec2 pivot = pTouches->getLocation();
        ball->setMoveVector(tap-pivot);
        ball->setIsMoving(true);
    }
}
void MissionLayer::onTouchCancelled(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
}