#include "Victory.h"
//#include "GameOver.h"
#include "HelloWorldScene.h"
//#include "JuegoFacil.h"
#include "SeleccionarNivel.h"
#include "audio/include/AudioEngine.h"

#include <iostream>
#include <fstream>
USING_NS_CC;

Scene* Victory::createScene()
{
    return Victory::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}



// on "init" you need to initialize your instance
bool Victory::init()
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
    auto GG = Sprite::create("Trofeo.png");
    GG->setPosition(Vec2(250, 800));
    this->addChild(GG);

    //Musica
    auto audio = AudioEngine::play2d("Win.mp3", true);
    //Botones

    auto _Menu = MenuItemImage::create("Menu.png", "Menu 1.png", CC_CALLBACK_1(Victory::BotonMenu, this));
    _Menu->setPosition(0, -120);
    auto _Exit = MenuItemImage::create("Exit.png", "Exit 1.png", CC_CALLBACK_1(Victory::menuCloseCallback, this));
    _Exit->setPosition(0, -280);


    auto menu1 = Menu::create(_Menu, _Exit, NULL);
    this->addChild(menu1, 1);

    std::string StrScore = std::to_string(score);
    //SLabel->createWithTTF(StrScore, "fonts/Marker Felt.ttf", 50);
    SLabel->setString(StrScore);
    SLabel->setSystemFontSize(45);
    SLabel->setColor(Color3B::YELLOW);
    SLabel->setPosition(Vec2(250, 600));
    this->addChild(SLabel);

    auto SLabel2 = Label::create();
    SLabel2->setString("Score:");
    SLabel2->setSystemFontSize(45);
    SLabel2->setColor(Color3B::YELLOW);
    SLabel2->setPosition(Vec2(250, 650));
    this->addChild(SLabel2);

    //Checar Score
    //Leer archivo Score
    std::string nombreArchivo = "BestScore.txt";
    std::ifstream archivo(nombreArchivo.c_str());
    int linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    //getline(archivo, linea);
    archivo >> linea;

    // Lo vamos imprimiendo
    int mejor = linea;
    if (mejor <= score)
    {
        //Guardar Score
        remove("BestScore.txt");
        std::string nombreArchivo = "BestScore.txt";
        std::ofstream archivo;
        // Abrimos el archivo
        archivo.open(nombreArchivo.c_str(), std::fstream::out);
        // Y le escribimos redirigiendo
        archivo << score;

        archivo.close();
    }

    
    
    

    return true;
}


void Victory::BotonMenu(cocos2d::Ref* pSender)
{
    cocos2d::AudioEngine::stopAll();
    auto HelloScene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(HelloScene);
}

void Victory::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}