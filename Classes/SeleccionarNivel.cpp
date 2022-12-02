#include "SeleccionarNivel.h"
#include "JuegoFacil.h"
#include "JuegoMedio.h"
#include "JuegoDificil.h"
#include "HelloWorldScene.h"
#include "audio/include/AudioEngine.h"
USING_NS_CC;

Scene* SeleccionarNivel::createScene()
{
    return SeleccionarNivel::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}



// on "init" you need to initialize your instance
bool SeleccionarNivel::init()
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

    //Botones
    auto _Easy = MenuItemImage::create("Easy.png", "Easy 1.png", "HelloWorld.png", CC_CALLBACK_1(SeleccionarNivel::BotonFacilon, this));
    _Easy->setPosition(0, 200);
    auto _Medium = MenuItemImage::create("Medium.png", "Medium 1.png", CC_CALLBACK_1(SeleccionarNivel::BotonMedion, this));
    _Medium->setPosition(0, 40);
    auto _Hard = MenuItemImage::create("Hard.png", "Hard 1.png", CC_CALLBACK_1(SeleccionarNivel::BotonDificilon, this));
    _Hard->setPosition(0, -120);
    auto _Back = MenuItemImage::create("Back.png", "Back 1.png", CC_CALLBACK_1(SeleccionarNivel::BotonBack, this));
    _Back->setPosition(0, -280);

    score = 9999;

    auto menu1 = Menu::create(_Easy, _Medium, _Hard,_Back, NULL);
    this->addChild(menu1, 1);

    return true;
}

void SeleccionarNivel::BotonFacilon(cocos2d::Ref* pSender)
{
    cocos2d::AudioEngine::stopAll();
    auto SceneFacil = Scene::createWithPhysics();
    //SceneFacil->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); //sI QUIERES QUE LO COLOREE O NO    
    //auto Scenef = JuegoFacil::createScene();
    SceneFacil->addChild(JuegoFacil::createScene());
    Director::getInstance()->replaceScene(SceneFacil);
}

void SeleccionarNivel::BotonMedion(cocos2d::Ref* pSender)
{
    
    cocos2d::AudioEngine::stopAll();
    auto SceneMed = Scene::createWithPhysics();
    //SceneFacil->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); //sI QUIERES QUE LO COLOREE O NO    
    //auto Scenef = JuegoFacil::createScene();
    SceneMed->addChild(JuegoMedio::createScene());
    Director::getInstance()->replaceScene(SceneMed);
}   

void SeleccionarNivel::BotonDificilon(cocos2d::Ref* pSender)
{
    cocos2d::AudioEngine::stopAll();
    auto SceneDif = Scene::createWithPhysics();
    //SceneFacil->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); //sI QUIERES QUE LO COLOREE O NO    
    //auto Scenef = JuegoFacil::createScene();
    SceneDif->addChild(JuegoDificil::createScene());
    Director::getInstance()->replaceScene(SceneDif);
    //Escena ya ganaste
}


void SeleccionarNivel::BotonBack(cocos2d::Ref* pSender)
{

    auto SceneHW = HelloWorld::createScene();
    Director::getInstance()->replaceScene(SceneHW);
}

void SeleccionarNivel::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}