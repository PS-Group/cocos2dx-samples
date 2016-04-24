#include "GameLevelScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool CGameLevelScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto map = make_node<CCustomMap>("tmx/layer_1.tmx");
    addChild(map);
    map->setScale(1.5f);

    m_hero = make_node<CHeroPuppet>(*map);
    m_hero->DoAfterUpdate([this]() {;
        Vec2 pos = m_hero->getPosition();
        setPosition(-pos + 0.5f * Vec2(getContentSize()));
    });
    m_heroPuppeteer = std::make_unique<CHeroPuppeteer>();
    m_heroPuppeteer->SetPuppet(m_hero);
    addChild(m_hero);
    
    return true;
}

void CGameLevelScene::onMenuClose(Ref* pSender)
{
    (void)pSender;
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void CGameLevelScene::onMenuPlay(Ref *pSender)
{
    (void)pSender;
    // TODO: implement.
}
