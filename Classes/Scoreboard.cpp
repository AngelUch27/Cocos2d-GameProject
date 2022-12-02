#include "Scoreboard.h"
#include "HelloWorldScene.h"

//#include "JuegoMedio.h"
//#include "JuegoDificil.h"
#include "audio/include/AudioEngine.h"

#include <iostream>
#include <fstream>
USING_NS_CC;

Scene* Scoreboard::createScene()
{
    return Scoreboard::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}



// on "init" you need to initialize your instance
bool Scoreboard::init()
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
    
    auto _Back = MenuItemImage::create("Back.png", "Back 1.png", CC_CALLBACK_1(Scoreboard::BotonBack, this));
    _Back->setPosition(0, -280);


    auto menu1 = Menu::create(_Back, NULL);
    this->addChild(menu1, 1);

    std::string StrScore = std::to_string(score);
    if (score == 9999)
    {
        StrScore = "0";
    }
    //SLabel->createWithTTF(StrScore, "fonts/Marker Felt.ttf", 50);
    SLabel->setString(StrScore);
    SLabel->setSystemFontSize(45);
    SLabel->setColor(Color3B::YELLOW);
    SLabel->setPosition(Vec2(250, 400));
    this->addChild(SLabel);

    auto SLabel2 = Label::create();
    SLabel2->setString("Last Score:");
    SLabel2->setSystemFontSize(45);
    SLabel2->setColor(Color3B::YELLOW);
    SLabel2->setPosition(Vec2(250, 450));
    this->addChild(SLabel2);

    auto SLabel3 = Label::create();
    SLabel3->setString("Best Score:");
    SLabel3->setSystemFontSize(45);
    SLabel3->setColor(Color3B::YELLOW);
    SLabel3->setPosition(Vec2(250, 650));
    this->addChild(SLabel3);

    //Leer archivo Score
    std::string nombreArchivo = "BestScore.txt";
    std::ifstream archivo(nombreArchivo.c_str());
    std::string linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    getline(archivo, linea);
    
        // Lo vamos imprimiendo
        std::string mejor = linea;
    
    
    
    //std::string Strmejor = std::to_string(mejor);
   

    auto SLabel4 = Label::create();
    SLabel4->setString(mejor);
    SLabel4->setSystemFontSize(45);
    SLabel4->setColor(Color3B::YELLOW);
    SLabel4->setPosition(Vec2(250, 600));
    this->addChild(SLabel4);
    

    return true;
}



void Scoreboard::BotonBack(cocos2d::Ref* pSender)
{
    auto SceneHW = HelloWorld::createScene();
    Director::getInstance()->replaceScene(SceneHW);
}



