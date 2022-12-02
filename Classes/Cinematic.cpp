#include "Cinematic.h"
#include "HelloWorldScene.h"

#include "audio/include/AudioEngine.h"


USING_NS_CC;

Scene* Cinematic::createScene()
{
    return Cinematic::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}



// on "init" you need to initialize your instance
bool Cinematic::init()
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

    //Fondo
    auto director = Director::getInstance();
    auto tamano = director->getWinSize();
   // SpriteMenuFondo = Sprite::create("Historia1.jpg");
    SpriteMenuFondo->setAnchorPoint(Vec2::ZERO);
    SpriteMenuFondo->setPosition(Vec2(0,150));
    SpriteMenuFondo->setScale(1.7);
    addChild(SpriteMenuFondo, 0);

    
    

    

    
    //SLabel->createWithTTF(StrScore, "fonts/Marker Felt.ttf", 50);
    SLabel->setString("Press ENTER to continue");
    SLabel->setSystemFontSize(45);
    SLabel->setColor(Color3B::YELLOW);
    SLabel->setPosition(Vec2(250, 40));
    this->addChild(SLabel);

   

   
    //std::string Strmejor = std::to_string(mejor);


    auto listenerKeyboard = EventListenerKeyboard().create();

    //Teclado
    listenerKeyboard->onKeyPressed = CC_CALLBACK_2(Cinematic::onKeyPressed, this);
    listenerKeyboard->onKeyReleased = CC_CALLBACK_2(Cinematic::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);



    return true;
}

void Cinematic::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    //Salir
    if (key == EventKeyboard::KeyCode::KEY_ENTER)
    {
        SpriteMenuFondo->setTexture("Historia2.png");
        SLabel->setString("Press ESCAPE to continue");
    }
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        auto SceneHW = HelloWorld::createScene();
        Director::getInstance()->replaceScene(SceneHW);
    }
}

void Cinematic::onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
    if (key == EventKeyboard::KeyCode::KEY_ENTER)
    {
        SpriteMenuFondo->setTexture("Historia2.jpg");
        SLabel->setString("Press ESCAPE to continue");
    }
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        cocos2d::AudioEngine::stopAll();
        auto SceneHW = HelloWorld::createScene();
        Director::getInstance()->replaceScene(SceneHW);
    }
}






