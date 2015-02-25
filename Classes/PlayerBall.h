//
//  PlayerBall.h
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 25..
//
//

#ifndef __SecondPuzzleGame__PlayerBall__
#define __SecondPuzzleGame__PlayerBall__

#include "GameSprite.h"

class PlayerBall : public GameSprite
{
protected:
public:
    PlayerBall()
    {}
    ~PlayerBall()
    {}
    static PlayerBall * createWithType(int type) {
        PlayerBall * ball = new PlayerBall();
        if(ball && ball->initWithFile("Ball-3.png"))
        {
            ball->autorelease();
            return ball;
        }
        CC_SAFE_DELETE(ball);
        return NULL;
    }
};

#endif /* defined(__SecondPuzzleGame__PlayerBall__) */
