//
//  Candy.cpp
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 25..
//
//

#include "Candy.h"
Candy::Candy() {
    
}
Candy::Candy(int _type) {
    type = _type;
}
Candy::~Candy() {
    
}

void Candy::SetBright()
{
    this->setOpacity(255);
    this->setbBright(true);
}

Candy * Candy::createWithTypeNumber(int type) {
    auto * candy = new Candy(type);
    if(candy && candy->initWithFile("Ball-3.png"))
    {
        candy->autorelease();
        return candy;
    }
    CC_SAFE_DELETE(candy);
    return NULL;
}