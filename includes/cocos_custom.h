#pragma once

#include "cocos2d.h"

namespace cc = cocos2d;

template <class T, class ...TArgs>
cc::RefPtr<T> make_node(TArgs&&... args)
{
    cc::RefPtr<T> ret(new (std::nothrow) T);
    if (ret && ret->init(std::forward<TArgs>(args)...)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_RELEASE(ret);
    return nullptr;
}

template <class T, class ...TArgs>
cc::RefPtr<cocos2d::Scene> make_scene(TArgs&&... args)
{
    auto scene = cocos2d::Scene::create();
    auto layer = make_node<T>(std::forward<TArgs>(args)...);
    scene->addChild(layer);

    return scene;
}
