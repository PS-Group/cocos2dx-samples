#pragma once
#include "cocos_custom.h"
#include "IMapPhysics.h"

/// Data model for my own custom maps.
class CCustomMap
        : public cocos2d::TMXTiledMap
        , public IMapPhysics
{
public:
    bool CanStandOn(const cocos2d::Vec2 &worldPosition)const override;

    bool init(const std::string& tmxFile);

private:
    bool InitPassabilityMap();
    bool LoadObstacles();

    std::vector<bool> m_passability;
    std::vector<cocos2d::Rect> m_obstacles;
};
