#include "HelloWorldScene.h"
//#include "MissionLayer.h"
#include "MissionUILayer.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    MissionUILayer * mission = new MissionUILayer();
    
    //MissionInfo 생성 및 초기화
    MissionInfo * missionInitData = new MissionInfo();
    auto gameSpriteData = new MissionInfo::GameSpriteData();
    for(int i=0; i<3; i++) {
        gameSpriteData->setType(i);
        gameSpriteData->setPositionX(100.f + 100.f * i);
        gameSpriteData->setPositionY(visibleSize.height * 0.8f);
        missionInitData->InsertGameSpriteInitData(gameSpriteData);
    }
    delete gameSpriteData;
    
    mission->LoadMission(missionInitData);
    mission->StartMission();
    //mission->PauseMission(true);
    
    //mission의 터치 활성화
    auto listener = EventListenerTouchOneByOne::create();
    listener->setEnabled(true);
    listener->onTouchBegan = CC_CALLBACK_2(MissionLayer::onTouchBegan, mission);
    listener->onTouchMoved = CC_CALLBACK_2(MissionLayer::onTouchMoved, mission);
    listener->onTouchEnded = CC_CALLBACK_2(MissionLayer::onTouchEnded, mission);
    listener->onTouchCancelled = CC_CALLBACK_2(MissionLayer::onTouchCancelled, mission);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, mission);
    
    this->addChild(mission);
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
