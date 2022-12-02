#//_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);


/*Touch
bool JuegoFacil::onTouchBegana(cocos2d::Touch* touch, cocos2d::Event* event, cocos2d::Sprite* Cuadrado)
{
    CCLOG("onTouchBegan x=%f,y = %f", touch->getLocation().x, touch->getLocation().y);
    Cuadrado->setPosition(touch->getLocation().x, touch->getLocation().y);
    return true;
}
bool JuegoFacil::onTouchMoveda(cocos2d::Touch* touch, cocos2d::Event* event)
{
    CCLOG("onTouchMoved x=%f,y = %f", touch->getLocation().x, touch->getLocation().y);
    return true;
}
bool JuegoFacil::onTouchEndeda(cocos2d::Touch* touch, cocos2d::Event* event)
{
    CCLOG("onTouchEnded x=%f,y = %f", touch->getLocation().x, touch->getLocation().y);
    return true;
}
*/
// Event Listener
    /*
    auto listener = EventListenerKeyboard().create();
    listener->onKeyPressed = CC_CALLBACK_2(JuegoFacil::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(JuegoFacil::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    */





    //listener->setSwallowTouches(true);

        /* Touch
        listener->onTouchBegan = CC_CALLBACK_2(JuegoFacil::onTouchBegana, this, Cuadrado);
        listener->onTouchMoved = CC_CALLBACK_2(JuegoFacil::onTouchMoveda, this);
        listener->onTouchEnded = CC_CALLBACK_2(JuegoFacil::onTouchEndeda, this);
        */