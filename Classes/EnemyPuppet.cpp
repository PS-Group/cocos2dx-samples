#include "EnemyPuppet.h"
#include "Resources.h"

USING_NS_CC;

bool CEnemyPuppet::init(IMapPhysics &mapPhysics)
{
    if (!CPuppet::init(mapPhysics))
    {
        return false;
    }
    m_body = Sprite::create(res::C_SPRITE_ENEMY);
    return true;
}

void CEnemyPuppet::onEnter()
{
    CPuppet::onEnter();
    addChild(m_body);
}

void CEnemyPuppet::onExit()
{
    m_body->removeFromParentAndCleanup(true);
    CPuppet::onExit();
}
