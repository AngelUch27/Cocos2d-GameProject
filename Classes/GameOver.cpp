#include "GameOver.h"
#include "HelloWorldScene.h"
#include "JuegoFacil.h"
#include "SeleccionarNivel.h"
#include "audio/include/AudioEngine.h"
USING_NS_CC;

Scene* GameOver::createScene()
{
    return GameOver::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}



// on "init" you need to initialize your instance
bool GameOver::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    //Tamaños de la ventana
    auto visibleSize = Director::getInstance()->getVisibleSize(); //Tamaño de la ventana
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //Game OVer
    auto GG = Sprite::create("GameOver.png");
    GG->setPosition(Vec2(250, 800));
    this->addChild(GG);

    //Musica
    auto audio = AudioEngine::play2d("GameOver.mp3", true);
    //Botones
    auto _Replay = MenuItemImage::create("TryAgain.png", "TryAgain 1.png", CC_CALLBACK_1(GameOver::BotonReplay, this));
    _Replay->setPosition(0, 40);
    auto _Menu = MenuItemImage::create("Menu.png", "Menu 1.png", CC_CALLBACK_1(GameOver::BotonMenu, this));
    _Menu->setPosition(0, -120);
    auto _Exit = MenuItemImage::create("Exit.png", "Exit 1.png", CC_CALLBACK_1(GameOver::menuCloseCallback, this));
    _Exit->setPosition(0, -280);


    auto menu1 = Menu::create(_Replay, _Menu, _Exit, NULL);
    this->addChild(menu1, 1);

    return true;
}

void GameOver::BotonReplay(cocos2d::Ref* pSender)
{
    cocos2d::AudioEngine::stopAll();
    cocos2d::AudioEngine::stopAll();
    auto SelNivScene = SeleccionarNivel::createScene();
    Director::getInstance()->replaceScene(SelNivScene);
}
void GameOver::BotonMenu(cocos2d::Ref* pSender)
{
    cocos2d::AudioEngine::stopAll();
    auto HelloScene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(HelloScene);
}

void GameOver::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
