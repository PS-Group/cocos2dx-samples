#pragma once
#include "cocos_custom.h"
#include "InputController.h"
#include "IPuppeteer.h"
#include "IGameWorld.h"
#include "EnemyPuppet.h"

class CEnemyPuppeteer : protected IPuppeteer
{
public:
    CEnemyPuppeteer(IGameWorld & world);

    void SetPuppet(CEnemyPuppet *enemy);

protected:
    void OnEnter() override;
    void Update(float delta) override;
    void OnExit() override;
    cocos2d::Vec2 GetVelocity() const override;

private:
    void UpdateAI();

    IGameWorld & m_world;
    CPuppetPtr m_enemy;
    std::unique_ptr<CInputController> m_controller;
    float m_timeSinceLastUpdate = 0;
    cocos2d::Vec2 m_velocity;
};

typedef std::unique_ptr<CEnemyPuppeteer> CEnemyPuppeteerPtr;
