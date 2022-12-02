#ifndef _Cinematic_SCENE_H_
#define _Cinematic_H_

#include "cocos2d.h"
extern cocos2d::UserDefault best;
extern int score;
class Cinematic : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Cinematic);

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);

    cocos2d::Sprite* SpriteMenuFondo = cocos2d::Sprite::create("Historia1.jpg");

    cocos2d::Label* SLabel = cocos2d::Label::create();

};

#endif // _HELLOWORLD_SCENE_H_