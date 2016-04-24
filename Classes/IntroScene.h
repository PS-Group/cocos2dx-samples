#pragma once
#include "cocos_custom.h"

class CIntroScene : public cocos2d::Layer
{
public:
    bool init() override;

private:
    // a selector callback
    void OnMenuClose(cocos2d::Ref* pSender);
    void OnMenuPlay(cocos2d::Ref* pSender);
};
