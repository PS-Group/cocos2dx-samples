#pragma once
#include "cocos_custom.h"

class IntroScene : public cocos2d::Layer
{
public:
    bool init() override;

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(IntroScene);
};
