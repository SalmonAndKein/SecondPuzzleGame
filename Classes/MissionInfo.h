//
//  MissionInfo.h
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 27..
//
//

#ifndef __SecondPuzzleGame__MissionInfo__
#define __SecondPuzzleGame__MissionInfo__

//#include "cocos2d.h"

class MissionInfo {
public:
    typedef struct spriteInfo
    {
        int type;
        float coord_x;
        float coord_y;
    } GameSpriteInfo;
protected:
    int targetListSize;
    GameSpriteInfo * targetList;
public:
    MissionInfo(int);
    ~MissionInfo();
    GameSpriteInfo * GetGameSpriteInfo(int idx);
    int GetSize();
};
#endif /* defined(__SecondPuzzleGame__MissionInfo__) */
