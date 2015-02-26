//
//  Candy.h
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 25..
//
//

#ifndef __SecondPuzzleGame__Candy__
#define __SecondPuzzleGame__Candy__

#include "GameSprite.h"

class Candy : public GameSprite
{
protected:
    int type;
    CC_SYNTHESIZE(bool, _bbright, bBright);
    
public:
    Candy();
    Candy(int);
    ~Candy();
    void SetBright();
    static Candy * createWithTypeNumber(int);
};

#endif /* defined(__SecondPuzzleGame__Candy__) */
