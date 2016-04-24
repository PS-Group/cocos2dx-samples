#pragma once
#include "cocos_custom.h"
#include "InputController.h"
#include "IPuppeteer.h"
#include "HeroPuppet.h"

class CHeroPuppeteer : protected IPuppeteer
{
public:
    void SetPuppet(CHeroPuppet *hero);

protected:
    void OnEnter() override;
    void Update(float delta) override;
    void OnExit() override;
    cocos2d::Vec2 GetVelocity() const override;

private:
    CPuppetPtr m_hero;
    std::unique_ptr<CInputController> m_controller;
};

typedef std::unique_ptr<CHeroPuppeteer> CHeroPuppeteerPtr;
