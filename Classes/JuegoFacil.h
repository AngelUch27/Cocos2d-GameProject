#ifndef __JuegoFacil_SCENE_H__
#define __JuegoFacil_H__

extern int score;

#include <string>
#include <iostream>
#include "cocos2d.h"

class JuegoFacil : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    void update(float delta);


    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(JuegoFacil);

    cocos2d::Sprite* SNave =cocos2d::Sprite::create("Nave2.png");
    cocos2d::Sprite* life = cocos2d::Sprite::create("Vida5.png");
    cocos2d::Sprite* SGas = cocos2d::Sprite::create();
    
   
    cocos2d::Rect rect1;
    cocos2d::Rect rect2;
    
    //void funcionSegundos(float detla);//BOrra
    void JuegoFacil::EnemigosMano();
    void funcionNaves(float delta);
    void funcionGas(float delta);
    void meChocaron(float delta);
    void checador(float delta);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    std::string nombres[4] = { "Meteoro.png","Meteoro2.png","Ovni.png","Ovni2.png" };
    //std::string NombreEnemigo;//Creo que se puede borrar
    bool posN = false;
    bool posNO = false;
    bool posO = false;
    bool posSO = false;
    bool posS = false;
    bool posSE = false;
    bool posE = false;
    bool posNE = false;
    int vida = 5;
    int litrosGas= 0;

    bool choqueC = false;
    bool recogerMonedas = false;

    //std::string StrScore = std::to_string(score);
    cocos2d::Label* SLabel = cocos2d::Label::create();

   
    int numSprite;
private:
    cocos2d::Vec2 pos;
    float agarrenseX;
    float agarramela;
   // cocos2d::Vec2 posEnemigos = cocos2d::Vec2(agarrenseX, agarrenseY);


};

#endif // __HELLOWORLD_SCENE_H__
