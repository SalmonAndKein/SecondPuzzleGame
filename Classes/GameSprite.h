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
    CC_SYNTHESIZE(bool, _bMoving, IsMoving);
public:
    GameSprite(){}
    ~GameSprite(){}
    void Move();
    inline float Radius();
    inline bool CheckCollision(GameSprite*);
};
float GameSprite::Radius()
{
    return getTexture()->getContentSize().width * 0.5f;
}
bool GameSprite::CheckCollision(GameSprite * _otherSprite)
{
    float diff_x = std::abs(this->getPosition().x - _otherSprite->getPosition().x);
    float diff_y = std::abs(this->getPosition().y - _otherSprite->getPosition().y);
    if (std::pow(diff_x, 2) + std::pow(diff_y, 2) <= std::pow(this->Radius() + _otherSprite->Radius(), 2))
        return true;
    else
        return false;
}
#endif /* defined(__SecondPuzzleGame__GameSprite__) */
