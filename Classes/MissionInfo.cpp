//
//  MissionInfo.cpp
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 27..
//
//

#include "MissionInfo.h"

MissionInfo::MissionInfo(int _size)
{
    numOfBall = 5;
    if(_size < 0)
    {
        _size = 0;
    }
    targetListSize =  _size;
    targetList = new GameSpriteInfo[targetListSize];
}
MissionInfo::~MissionInfo()
{
    delete [] targetList;
}
MissionInfo::GameSpriteInfo * MissionInfo::GetGameSpriteInfo(int idx) {
    if(idx<0 || idx>=targetListSize) {
        return NULL;
    }
    return &targetList[idx];
}
int MissionInfo::GetSize() {
    return targetListSize;
}