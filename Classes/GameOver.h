#ifndef __GameOver_SCENE_H__
#define __GameOver_H__

#include "cocos2d.h"

class GameOver : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);

    void BotonExit(Ref* pSender);
    void BotonMenu(Ref* pSender);
    void BotonReplay(Ref* pSender);


};

#endif // __HELLOWORLD_SCENE_H__
