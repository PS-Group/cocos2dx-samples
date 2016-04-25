#pragma once
#include "cocos_custom.h"
#include "CustomMap.h"
#include "HeroPuppet.h"
#include "HeroPuppeteer.h"
#include "EnemyPuppeteer.h"
#include "IGameWorld.h"

class CGameLevelScene
        : public cocos2d::Layer
        , public IGameWorld
{
public:
    bool init() override;

protected:
    // IGameWorld interface
    cocos2d::Vec2 GetHeroPosition() const override;
    IMapPhysics &GetMap() override;

private:
    void SpawnHero();
    void SpawnEnemies();

    cocos2d::RefPtr<CHeroPuppet> m_hero;
    CCustomMap *m_customMap = nullptr;
    CHeroPuppeteerPtr m_heroPuppeteer;
    std::vector<CEnemyPuppeteerPtr> m_enemyPuppeteers;

};
