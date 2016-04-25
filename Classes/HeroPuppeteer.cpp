#include "HeroPuppeteer.h"

USING_NS_CC;

namespace
{
const Vec2 HERO_SPEED(150, 150);
}

void CHeroPuppeteer::SetPuppet(CHeroPuppet *hero)
{
    m_hero = hero;
    if (m_hero)
    {
        m_hero->SetPuppeteer(this);
    }
}

void CHeroPuppeteer::OnEnter()
{
    m_controller = std::make_unique<CInputController>(HERO_SPEED);
}

void CHeroPuppeteer::Update(float delta)
{
    (void)delta;
}

void CHeroPuppeteer::OnExit()
{
    m_controller.reset();
}

cocos2d::Vec2 CHeroPuppeteer::GetVelocity() const
{
    return m_controller->GetSpeed();
}
