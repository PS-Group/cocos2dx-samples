#pragma once
#include "cocos_custom.h"
#include "Puppet.h"

class CHeroPuppet : public CPuppet
{
public:
    bool init(IMapPhysics &mapPhysics);
    void onEnter() override;
    void onExit() override;
    void update(float delta) override;

    void DoAfterUpdate(const std::function<void()> &func);

private:
    cocos2d::RefPtr<cocos2d::Sprite> m_body;
    std::function<void()> m_afterUpdate;
};
