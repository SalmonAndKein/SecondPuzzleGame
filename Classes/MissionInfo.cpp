//
//  MissionInfo.cpp
//  SecondPuzzleGame
//
//  Created by Salmon on 2015. 2. 27..
//
//

#include "MissionInfo.h"

MissionInfo::MissionInfo(int num, float air, float gravity)
{
    _numOfBall = num;
    _airResistance = air;
    _gravity = gravity;
}
MissionInfo::~MissionInfo()
{
    while (!GameSpriteInitDataArray.empty()) {
        GameSpriteData * element = GameSpriteInitDataArray.back();
        delete element;
        GameSpriteInitDataArray.pop_back();
    }
}
int MissionInfo::InsertGameSpriteInitData(GameSpriteData * _gameSprite) {
    if(_gameSprite) {
        GameSpriteData * gameSprite = new GameSpriteData(*_gameSprite);
        GameSpriteInitDataArray.push_back(gameSprite);
        return GetGameSpriteArraySize();
    }
    return 0;
}
MissionInfo::GameSpriteData * MissionInfo::GetGameSpriteInitData(int idx) {
    if(idx<0 || idx>=GameSpriteInitDataArray.size()) {
        return NULL;
    }
    return GameSpriteInitDataArray[idx];
}
int MissionInfo::GetGameSpriteArraySize() {
    return (int) GameSpriteInitDataArray.size();
}