#include "HelloWorldScene.h"
#include "MissionLayer.h"

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
    
    
    
    
    MissionLayer * mission = new MissionLayer();
    MissionInfo * testMission = new MissionInfo(5);
    
    for(int i=0; i<testMission->GettargetListSize(); i++) {
        auto targetData = testMission->GetGameSpriteInfo(i);
        targetData->type = i;
        targetData->coord_x = 100 + 100*i;
        targetData->coord_y = visibleSize.height * 0.8;
    }
    mission->LoadMission(testMission);
    this->addChild(mission);
    
    //update 활성화
    this->scheduleUpdate();
    
    //터치 활성화
    auto listener = EventListenerTouchOneByOne::create();
    listener->setEnabled(true);
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    //터치 이벤트를 처리할 타깃 레이어 선택
    targetLayer = mission;
    return true;
}

void HelloWorld::update(float dt) {
    targetLayer->update(dt);
}

bool HelloWorld::onTouchBegan(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
    return targetLayer->onTouchBegan(pTouches, event);
}

void HelloWorld::onTouchMoved(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
    targetLayer->onTouchMoved(pTouches, event);
}
void HelloWorld::onTouchEnded(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
    targetLayer->onTouchEnded(pTouches, event);
}
void HelloWorld::onTouchCancelled(cocos2d::Touch *pTouches,cocos2d::Event *event)
{
    targetLayer->onTouchCancelled(pTouches, event);
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
