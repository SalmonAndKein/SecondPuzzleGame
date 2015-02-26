//
//  GameSprite.h
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 25..
//
//

#ifndef __SecondPuzzleGame__GameSprite__
#define __SecondPuzzleGame__GameSprite__

#include "cocos2d.h"

class GameSprite : public cocos2d::Sprite {
protected:
    CC_SYNTHESIZE(cocos2d::Vec2, _moveVec, MoveVector);
    CC_SYNTHESIZE(bool, _bGravity, Gravity);
public:
    GameSprite(){}
    ~GameSprite(){}
    void Move();
    float Radius()
    {
        return getTexture()->getContentSize().width * 0.5f;
    }
};
#endif /* defined(__SecondPuzzleGame__GameSprite__) */
