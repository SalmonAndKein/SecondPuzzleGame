//
//  LineContainer.h
//  SecondPuzzleGame
//
//  Created by Myloi Mellanc on 2015. 2. 27..
//
//

#ifndef __SecondPuzzleGame__LineContainer__
#define __SecondPuzzleGame__LineContainer__

#include "cocos2d.h"

enum{
    LINE_NONE,
    LINE_DRAW
};

class LineContainer : public cocos2d::Node
{
protected:
    CC_SYNTHESIZE(int, line_type, LineType);
    CC_SYNTHESIZE(cocos2d::Vec2, tap, Tap);
    CC_SYNTHESIZE(cocos2d::Vec2, pivot, Pivot);
    cocos2d::CustomCommand cmd;
public:
    CREATE_FUNC(LineContainer);
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags);
    void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);
    
};

#endif /* defined(__SecondPuzzleGame__LineContainer__) */
