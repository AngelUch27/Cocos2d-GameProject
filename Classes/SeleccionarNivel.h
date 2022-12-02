#ifndef __SeleccionarNivel_SCENE_H__
#define __SeleccionarNivel_H__

#include "cocos2d.h"

class SeleccionarNivel : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(SeleccionarNivel);

    void BotonFacilon(Ref* pSender);
    void BotonMedion(Ref* pSender);
    void BotonDificilon(Ref* pSender);
    void BotonBack(Ref* pSender);


};

#endif // __HELLOWORLD_SCENE_H__
