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
    class GameSpriteData
    {
    public:
        CC_SYNTHESIZE(int,_type,Type)
        CC_SYNTHESIZE(float,_coord_x,PositionX)
        CC_SYNTHESIZE(float,_coord_y,PositionY)
        GameSpriteData() : GameSpriteData(0,0.f,0.f) {}
        GameSpriteData(int type, float x, float y) {
            setType(type);
            setPositionX(x);
            setPositionY(y);
        }
    };
protected:
    CC_SYNTHESIZE_READONLY(float,_gravity,GravityFactor)
    CC_SYNTHESIZE_READONLY(float,_airResistance,AirResistanceFacotor)
    CC_SYNTHESIZE_READONLY(int, _numOfBall, NumberOfBall)
    std::vector<GameSpriteData*> GameSpriteInitDataArray;
public:
    MissionInfo(int num, float air, float gravity);
    ~MissionInfo();
    int InsertGameSpriteInitData(GameSpriteData*);
    GameSpriteData * GetGameSpriteInitData(int idx);
    int GetGameSpriteArraySize();
};
#endif /* defined(__SecondPuzzleGame__MissionInfo__) */
