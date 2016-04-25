#pragma once
#include "cocos_custom.h"
#include "Puppet.h"

class CEnemyPuppet : public CPuppet
{
public:
    bool init(IMapPhysics &mapPhysics);
    void onEnter() override;
    void onExit() override;

private:
    cocos2d::RefPtr<cocos2d::Sprite> m_body;
};
