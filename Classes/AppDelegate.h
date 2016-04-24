#pragma once
#include "cocos_custom.h"

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class CAppDelegate : private cocos2d::Application
{
public:
    CAppDelegate();
    ~CAppDelegate();

    void initGLContextAttrs() override;

    /**
    @brief    Implement Director and Scene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    bool applicationDidFinishLaunching() override;

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    void applicationDidEnterBackground() override;

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    void applicationWillEnterForeground() override;
};

