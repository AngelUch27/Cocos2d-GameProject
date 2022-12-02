#ifndef _Score_SCENE_H_
#define _Score_H_

#include "cocos2d.h"
extern cocos2d::UserDefault best;
extern int score;
class Scoreboard : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Scoreboard);

    void BotonBack(Ref* pSender);
    
    cocos2d::Label* SLabel = cocos2d::Label::create();

};

#endif // _HELLOWORLD_SCENE_H_