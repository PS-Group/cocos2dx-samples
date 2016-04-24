#pragma once
#include "cocos_custom.h"
#include "CustomMap.h"
#include "HeroPuppet.h"
#include "HeroPuppeteer.h"

class CGameLevelScene : public cocos2d::Layer
{
public:
    bool init() override;

private:
    // a selector callback
    void onMenuClose(cocos2d::Ref* pSender);
    void onMenuPlay(cocos2d::Ref* pSender);

    cocos2d::RefPtr<CHeroPuppet> m_hero;
    CHeroPuppeteerPtr m_heroPuppeteer;
};
