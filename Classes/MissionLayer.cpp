//
//  MissionLayer.cpp
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 25..
//
//

#include "MissionLayer.h"
enum
{
    Candy
};

USING_NS_CC;

MissionLayer::MissionLayer() {
    bMissionLoaded = false;
    bGameOver = false;
}
MissionLayer::~MissionLayer() {
}
void MissionLayer::UnloadMission() {
    if(bMissionRunning)
        StopMission();
    movingObjectArray.clear();
    candyArray.clear();
    removeAllChildren();
    bMissionLoaded = false;
}

void MissionLayer::BuildInstance()
{
    screenSize = Director::getInstance()->getWinSize();
    
    //라인 그리기용 클래스 생성
    linecontainer = LineContainer::create();
    this->addChild(linecontainer);
    linecontainer->retain();
    
    //볼 생성
    ball = PlayerBall::createWithType(0);
    movingObjectArray.push_back(ball);
    this->addChild(ball);
    this->retain();

}

void MissionLayer::Reset()
{
    screenSize = Director::getInstance()->getWinSize();

    //볼 초기화
    ballStartPoint = cocos2d::Vec2(screenSize.width * 0.5,screenSize.height * 0.1);
    ball->setIsMoving(false);
    ball->setPosition(ballStartPoint);
    ball->setMoveVector(cocos2d::Vec2(0,0));
    if (bGameOver)
    {
        //캔디 제거
        int count = (int)movingObjectArray.size();
        
        for (int i=0; i<count; i++)
        {
            if (movingObjectArray[i]->getWhatName()=='c')
            {
                this->removeChild(movingObjectArray[i]);
            }
        }

        movingObjectArray.clear();
        movingObjectArray.push_back(ball);
        candyArray.clear();
    }
    
    //게임 정보 초기화
    
    bGameOver = false;
    bMissionRunning = false;
    bMissionLoaded = false;
    
}

void MissionLayer::Generate()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    info = new MissionInfo(5,0.99, -0.98);
    auto gameSpriteData = new MissionInfo::GameSpriteData();
    for(int i=0; i<3; i++) {
        gameSpriteData->setType(i);
        gameSpriteData->setPositionX(100.f + 100.f * i);
        gameSpriteData->setPositionY(visibleSize.height * 0.2f);
        info->InsertGameSpriteInitData(gameSpriteData);
    }
    delete gameSpriteData;
    
}

bool MissionLayer::LoadMission() {
    if(bMissionLoaded || info->GetGameSpriteArraySize() <= 0)
        return false;
    
    screenSize = Director::getInstance()->getWinSize();
    
    for(int i=0; i<info->GetGameSpriteArraySize(); i++) {
        //캔디 생성
        auto candyInitData = info->GetGameSpriteInitData(i);
        auto newCandy = Candy::createWithTypeNumber(candyInitData->getType());
        movingObjectArray.push_back(newCandy);
        candyArray.push_back(newCandy);
        this->addChild(newCandy,0,Candy);
        //캔디 초기화
        newCandy->setPosition(cocos2d::Vec2(candyInitData->getPositionX(), candyInitData->getPositionY()));
        newCandy->setIsMoving(false);
        newCandy->setMoveVector(cocos2d::Vec2(0,0));
        
        cocos2d::log("%d",(int)movingObjectArray.size());
    }
    
    gravityFactor = info->getGravityFactor();
    airResistanceFactor = info->getAirResistanceFacotor();
    curNumOfBall = info->getNumberOfBall();
    bMissionLoaded = true;
    
    return true;
}
void MissionLayer::StartMission() {
    this->scheduleUpdate();
    bMissionRunning = true;
}
void MissionLayer::StopMission() {
    this->unscheduleUpdate();
    bMissionRunning = false;
}
void MissionLayer::PauseMission(bool bOption) {
    if(bOption == true) {
        this->unscheduleUpdate();
        bMissionRunning = false;
    } else {
        this->scheduleUpdate();
        bMissionRunning = true;
    }
}
void MissionLayer::SetGameOver() {
    bGameOver = true;
    StopMission();
    cocos2d::log("GameOver");
}
void MissionLayer::update(float dt)
{
    screenSize = cocos2d::Director::getInstance()->getWinSize();
    
    //벽 충돌 판단
    cocos2d::Vec2 vec = ball->getMoveVector();
    if (ball->getPosition().y>=screenSize.height || ball->getPosition().y<=0)
    {
        vec.y = -vec.y;
    }
    if (ball->getPosition().x>=screenSize.width || ball->getPosition().x<=0)
    {
        vec.x = -vec.x;
    }
    ball->setMoveVector(vec);
    
    for(int i=0; i<movingObjectArray.size(); i++)
    {
        //움직임이 적용되는 대상에게만 공식 대입
        if(movingObjectArray[i]->getIsMoving())
        {
            //중력값 gravity 적용
            cocos2d::Vec2 curMoveVec = movingObjectArray[i]->getMoveVector();
            curMoveVec.y = curMoveVec.y + gravityFactor;
            //만약 벡터의 절대값이 0.001보다 작을경우 값을 0으로 변경
            if(std::abs(curMoveVec.x) < 0.001)
                curMoveVec.x = 0;
            if(std::abs(curMoveVec.y) < 0.001)
                curMoveVec.y = 0;
            //수정된 값에 따라 벡터값 재적용 후 이동
            movingObjectArray[i]->setMoveVector(curMoveVec);
            movingObjectArray[i]->Move();
            if(movingObjectArray[i]->getPosition().y <= 0) {
                movingObjectArray[i]->setIsMoving(false);
                //볼이 떨어지면 하트 감소, 게임오버
                if (movingObjectArray[i] == ball)
                {
                    curNumOfBall--;
                    if (curNumOfBall>0)
                        movingObjectArray[i]->setPosition(ballStartPoint);
                    else
                        SetGameOver();
                }
            }
        }
        //캔디가 맞았을 경우 이동 활성화
        for(int i=0; i<candyArray.size(); i++) {
            if(ball->CheckCollision(candyArray[i])) {
                candyArray[i]->setIsMoving(true);
            }
        }
        
        
    }
}

bool MissionLayer::onTouchBegan(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
    if (bGameOver)
    {
        this->Reset();
        this->LoadMission();
        this->StartMission();
        return false;
    }
    
    //터치가 볼에 닿았을 경우 라인 콘테이너의 시작점과 끝점을 선정, 그 후 라인 타입(라인을 그려도 된다고 지시)을 바꾼다.
    if (pTouches)
    {
        float dx = ball->getPosition().x - pTouches->getLocation().x;
        float dy = ball->getPosition().y - pTouches->getLocation().y;
        
        if (dx*dx + dy*dy <= pow(ball->Radius(), 2))
        {
            tap = pTouches->getLocation();
            linecontainer->setTap(ball->getPosition());
            linecontainer->setPivot(ball->getPosition());
            linecontainer->setLineType(LINE_DRAW);
            return true;
        }
    }
    return false;
}
void MissionLayer::onTouchMoved(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
    //그릴 라인의 끝부분을 터치가 이루어지는 곳으로 설정(draw메서드는 자동으로 호출된다.)
    linecontainer->setPivot(pTouches->getLocation());
}
void MissionLayer::onTouchEnded(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
    if (pTouches)
    {
        //터치를 끌은 만큼 이동 벡터를 만들고 볼의 이동벡터에 적용시킨다. 이후 볼은 update매서드에 의해 자동으로 이동함, 그리고 라인 콘테이너를 비활성으로 만듬
        cocos2d::Vec2 pivot = pTouches->getLocation();
        ball->setMoveVector(tap-pivot);
        ball->setIsMoving(true);
        linecontainer->setLineType(LINE_NONE);
    }
}
void MissionLayer::onTouchCancelled(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
}


