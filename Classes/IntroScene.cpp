#include "IntroScene.h"
#include "GameLevelScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool CIntroScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(CIntroScene::OnMenuClose, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto playLabel = Label::createWithTTF("Play Now!", "fonts/Marker Felt.ttf", 24);
    auto playItem = MenuItemLabel::create(playLabel, CC_CALLBACK_1(CIntroScene::OnMenuPlay, this));

    playItem->setPosition(Vec2(origin.x + 0.5f * visibleSize.width - closeItem->getContentSize().width/2 ,
                               origin.y + 0.8f * visibleSize.height));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, playItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void CIntroScene::OnMenuClose(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void CIntroScene::OnMenuPlay(Ref *pSender)
{
    (void)pSender;
    Director::getInstance()->pushScene(make_scene<CGameLevelScene>());
}
