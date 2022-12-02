#include "JuegoMedio.h"
//#include "JuegoFacil.h"
#include "JuegoDificil.h"
#include "SeleccionarNivel.h"
#include "audio/include/AudioEngine.h"
#include "GameOver.h"
#include <chrono>

USING_NS_CC;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

Scene* JuegoMedio::createScene()
{
    Scene* scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vect(0, 0));
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->addChild(JuegoMedio::create());
    //return JuegoFacil::create();
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}



// on "init" you need to initialize your instance
bool JuegoMedio::init()
{
    //////////////////////////////
    // 1. super init first


    //Tamaños de la ventana
    auto visibleSize = Director::getInstance()->getVisibleSize(); //Tamaño de la ventana
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto director = Director::getInstance();
    auto tamano = director->getWinSize();

    auto SpriteMenuFondo = Sprite::create("Fondo2.png");
    SpriteMenuFondo->setAnchorPoint(Vec2::ZERO);
    SpriteMenuFondo->setScale(1);
    SpriteMenuFondo->setPosition(0, 0);
    //SpriteMenuFondo->setRotation(180);
    addChild(SpriteMenuFondo, 0);

    //SNave->setAnchorPoint(Vec2(SNave->getContentSize().width/2,SNave->getContentSize().height));
    SNave->setPosition(220, 100);

    addChild(SNave, 1);

    //Sprite Vidas

    life->setPosition(Vec2(400, 800));
    addChild(life, 5);
    SGas->setPosition(Vec2(100, 800));
    addChild(SGas, 5);

    //Audio
    auto audio = AudioEngine::play2d("Level2.mp3", true);


    // auto action = Sequence::create(RotateBy::create(2, 100), MoveBy::create(5, Point(100, -50)), NULL);

    auto listenerKeyboard = EventListenerKeyboard().create();

    //Teclado
    listenerKeyboard->onKeyPressed = CC_CALLBACK_2(JuegoMedio::onKeyPressed, this);
    listenerKeyboard->onKeyReleased = CC_CALLBACK_2(JuegoMedio::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);


    //Fisica
    auto fisiquilla = PhysicsBody::createBox(Size(SNave->getContentSize().width, SNave->getContentSize().height));
    fisiquilla->setDynamic(false);
    fisiquilla->setDynamic(false);
    fisiquilla->setCollisionBitmask(1);
    fisiquilla->setContactTestBitmask(true);
    SNave->setPhysicsBody(fisiquilla);

    //adds contact event listener
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(JuegoMedio::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);


    this->scheduleUpdate(); //this->
    //Enemigos


    this->schedule(CC_SCHEDULE_SELECTOR(JuegoMedio::funcionNaves), 2.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(JuegoMedio::funcionGas), 17.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(JuegoMedio::meChocaron), .1);
    this->schedule(CC_SCHEDULE_SELECTOR(JuegoMedio::checador), .2);

    //std::string nombres[4] = { "Meteoro.png","Meteoro2.png","Ovni.png","Ovni2.png" };
    int numSprite;

    std::string StrScore = std::to_string(score);
    //SLabel->createWithTTF(StrScore, "fonts/Marker Felt.ttf", 50);
    SLabel->setString(StrScore);
    SLabel->setSystemFontSize(45);
    SLabel->setColor(Color3B::YELLOW);
    SLabel->setPosition(Vec2(250, 800));
    this->addChild(SLabel);


    return true;
    return false;

}

void JuegoMedio::checador(float Delta)
{

    score--;
    std::string StrScore = std::to_string(score);
    SLabel->setString(StrScore);
}

//Trabaja solo
bool JuegoMedio::onContactBegin(PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();

    if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
    {
        AudioEngine::play2d("Golpe.mp3", false);
        vida--;
        score -= 1000;
        choqueC = true;
    }

    if ((1 == a->getCollisionBitmask() && 3 == b->getCollisionBitmask()) || (3 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
    {
        //AudioEngine::play2d("StarSound.mp3", false);
        if (a->getCollisionBitmask() == 3)
        {
            a->getNode()->removeFromParent();
        }
        else
        {
            b->getNode()->removeFromParent();
        }
        recogerMonedas = true;
        litrosGas++;
    }

    if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
    {
        //AudioEngine::play2d("StarSound.mp3", false);
        if (a->getCollisionBitmask() == 2)
        {
            a->getNode()->removeFromParent();
        }
        else
        {
            b->getNode()->removeFromParent();
        }

    }

    return true;
}
//Funcion choque
//1 Nave
//2 Enemigos
//3Monedas
void JuegoMedio::meChocaron(float delta)
{
    if (choqueC)
    {

        auto pum = RotateBy::create(.3, 360);
        SNave->runAction(pum);


        choqueC = false;
    }
    if (recogerMonedas)
    {
        AudioEngine::play2d("Gas.mp3", false);

        recogerMonedas = false;

    }

    //Vidas
    if (vida == 4)
    {
        life->setTexture("Vida4.png");
    }
    if (vida == 3)
    {
        life->setTexture("Vida3.png");
    }
    if (vida == 2)
    {
        life->setTexture("Vida2.png");
    }
    if (vida == 1)
    {
        life->setTexture("Vida1.png");
    }
    if (vida <= 0)
    {
        cocos2d::AudioEngine::stopAll();
        auto GGScene = GameOver::createScene();
        Director::getInstance()->replaceScene(GGScene);
    }

    //Gas
    if (litrosGas == 3)
    {
        SGas->setTexture("Gas3.png");
        cocos2d::AudioEngine::stopAll();
        auto SceneDif = Scene::createWithPhysics();
        //SceneFacil->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); //sI QUIERES QUE LO COLOREE O NO    
        //auto Scenef = JuegoFacil::createScene();
        SceneDif->addChild(JuegoDificil::createScene());
        Director::getInstance()->replaceScene(SceneDif);
        //Escena ya ganaste
    }
    if (litrosGas == 2)
    {
        SGas->setTexture("Gas2.png");
    }
    if (litrosGas == 1)
    {
        SGas->setTexture("Gas1.png");
    }
}
//Monedas
void JuegoMedio::funcionGas(float delta)
{
    agarramela = rand() % 450;
    cocos2d::Sprite* Gas = cocos2d::Sprite::create("Gas.png");
    auto cuerpo2 = PhysicsBody::createBox(Size(Gas->getContentSize().width, Gas->getContentSize().height));
    cuerpo2->setDynamic(false);
    cuerpo2->setCollisionBitmask(3);
    cuerpo2->setContactTestBitmask(true);
    Gas->setPosition(agarramela, 1000);
    Gas->setPhysicsBody(cuerpo2);
    auto avanzarOvnis = MoveBy::create(6, Vec2(0, -1100));
    auto secuencia = Sequence::create(avanzarOvnis, RemoveSelf::create(), NULL);
    this->addChild(Gas, 1);
    Gas->runAction(secuencia->clone());

}
void JuegoMedio::funcionNaves(float delta2)
{
    agarrenseX = 50 + rand() % 450;

    numSprite = rand() % 4;
    //Moneda

    //Enemigos
    auto obstaculo = Sprite::create(nombres[numSprite]);
    //Fisica    
    auto cuerpo = PhysicsBody::createBox(Size(obstaculo->getContentSize().width, obstaculo->getContentSize().height));
    cuerpo->setDynamic(false);
    cuerpo->setCollisionBitmask(2);
    cuerpo->setContactTestBitmask(true);
    obstaculo->setPosition(agarrenseX, 1000);


    obstaculo->setPhysicsBody(cuerpo);
    auto avanzarOvnis = MoveBy::create(2.2, Vec2(0, -1100));

    auto secuencia = Sequence::create(avanzarOvnis, RemoveSelf::create(), NULL);
    this->addChild(obstaculo, 1);
    obstaculo->runAction(secuencia->clone());


}


void JuegoMedio::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto pos = SNave->getPosition();

    //Derecha
    if (key == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
    {
        posE = true;
    }
    //Izquierda
    if (key == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
    {
        posO = true;
    }

    //Arriba
    if (key == EventKeyboard::KeyCode::KEY_UP_ARROW)
    {
        posN = true;
    }
    //Abajo
    if (key == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
    {
        posS = true;
    }

    //Salir
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        cocos2d::AudioEngine::stopAll();
        auto SceneSelNivel = SeleccionarNivel::createScene();
        Director::getInstance()->replaceScene(SceneSelNivel);
    }
}

void JuegoMedio::onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
    if (key == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
    {
        //CCLOG("Key A pressed");
        SNave->setRotation(0);
        SNave->stopAllActions();
        posN = false;
        posE = false;
        posS = false;
        posO = false;
    }

    if (key == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
    {
        //CCLOG("Key A pressed");
        SNave->setRotation(0);
        SNave->stopAllActions();
        posN = false;
        posE = false;
        posS = false;
        posO = false;
    }

    if (key == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
    {
        //CCLOG("Key A pressed");
        SNave->setRotation(0);
        SNave->stopAllActions();
        posN = false;
        posE = false;
        posS = false;
        posO = false;
    }

    if (key == EventKeyboard::KeyCode::KEY_UP_ARROW)
    {
        //CCLOG("Key A pressed");
        SNave->setRotation(0);
        SNave->stopAllActions();
        posN = false;
        posE = false;
        posS = false;
        posO = false;
    }


}

//Enemigo1
void JuegoMedio::update(float deltaTime)
{

    pos = SNave->getPosition();
    //Derecha
    if (pos.x <= 420 && posE == true && choqueC == false)
    {
        //auto action = RepeatForever::create(MoveBy::create(.1, Vec2(20, 0)));
        auto action = MoveBy::create(.1, Vec2(10, 0));
        if (posS == true)
        {
            SNave->setRotation(150);
        }
        if (posS == false)
        {
            SNave->setRotation(30);
        }
        SNave->setRotation(30);
        SNave->runAction(action);
    }


    //Izquierda
    if (pos.x >= 80 && posO == true && choqueC == false)
    {
        //auto action = RepeatForever::create(MoveBy::create(.1, Vec2(-20, 0)));
        auto action = MoveBy::create(.1, Vec2(-10, 0));
        SNave->setRotation(-30);
        if (posS == true)
        {
            SNave->setRotation(-150);
        }
        SNave->setRotation(-30);
        if (posS == false)
        {
            SNave->setRotation(-30);
        }
        SNave->runAction(action);
        posO = true;
    }

    //Arriba
    if (pos.y <= 800 && posN == true && choqueC == false)
    {
        //auto action = RepeatForever::create(MoveBy::create(.1, Vec2(0, 20)));
        auto action = MoveBy::create(.1, Vec2(0, 10));
        SNave->setRotation(0);
        if (posO == true)
        {
            SNave->setRotation(-30);
        }
        if (posE == true)
        {
            SNave->setRotation(30);
        }
        SNave->runAction(action);
        posN = true;
    }

    //Abajo
    if (pos.y >= 90 && posS == true && choqueC == false)
    {
        //auto action = RepeatForever::create(MoveBy::create(.1, Vec2(0, -20)));
        auto action = MoveBy::create(.1, Vec2(0, -10));
        SNave->setRotation(180);
        if (posO == true)
        {
            SNave->setRotation(-150);
        }
        if (posE == true)
        {
            SNave->setRotation(150);
        }
        posN = false;
        posS = true;
        SNave->runAction(action);
    }
}



void JuegoMedio::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


};