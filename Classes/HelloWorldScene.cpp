#include "HelloWorldScene.h"
#include "SeleccionarNivel.h"
#include "Scoreboard.h"
#include "Cinematic.h"

#include "audio/include/AudioEngine.h"



USING_NS_CC;


Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}



// on "init" you need to initialize your instance
bool HelloWorld::init()
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

    //Audio
    auto audio = AudioEngine::play2d("Menu.mp3",true);
    
    //Fondo
    auto director = Director::getInstance();
    auto tamano = director->getWinSize();
    auto SpriteMenuFondo = Sprite::create("FondoMenu1.jpg");
    SpriteMenuFondo->setAnchorPoint(Vec2::ZERO);
    SpriteMenuFondo->setPosition(0, 0);
    addChild(SpriteMenuFondo, 0);

    

    
    //Menu
    auto _Start = MenuItemImage::create("Start.png", "Start 1.png","HelloWorld.png", CC_CALLBACK_1(HelloWorld::BotonStart, this));
    _Start->setPosition(0,200);
    auto _Cinematic = MenuItemImage::create("Cinematic.png", "Cinematic 1.png", CC_CALLBACK_1(HelloWorld::BotonCinematic, this));
    _Cinematic->setPosition(0, 40);
    auto _Score = MenuItemImage::create("Score.png", "Score 1.png", CC_CALLBACK_1(HelloWorld::BotonScore, this));
    _Score->setPosition(0, -120);
    auto _Exit = MenuItemImage::create("Exit.png", "Exit 1.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    _Exit->setPosition(0, -280);
    
    auto menu = Menu::create(_Start,_Cinematic,_Score,_Exit, NULL);
    this->addChild(menu, 1);

       
    return true;
}

//Boton Start
void HelloWorld::BotonStart(cocos2d::Ref* pSender)
{
    
    auto SceneSelNivel = SeleccionarNivel::createScene();
    Director::getInstance()->replaceScene(SceneSelNivel);
}

void HelloWorld::BotonScore(cocos2d::Ref* pSender)
{

    auto SceneScore = Scoreboard::createScene();
    Director::getInstance()->replaceScene(SceneScore);
}

void HelloWorld::BotonCinematic(cocos2d::Ref* pSender)
{

    auto SceneCine = Cinematic::createScene();
    Director::getInstance()->replaceScene(SceneCine);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
