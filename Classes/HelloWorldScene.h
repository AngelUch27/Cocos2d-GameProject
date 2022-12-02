#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"


class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
    /*cocos2d::Sprite* _Start; //Boton de inicio
    cocos2d::Sprite* _Cinematica; //Boton de inicio
    cocos2d::Sprite* _Scoreboard; //Boton de inicio
    cocos2d::Sprite* _Exit; //Boton de inicio
    */
    
    //Menu
    //cocos2d::Menu *menu;
    void BotonStart(Ref* pSender);
    void BotonCinematic(Ref* pSender);
    void BotonScore(Ref* pSender);
    void bexit(Ref* pSender);
   
};

#endif // __HELLOWORLD_SCENE_H__
