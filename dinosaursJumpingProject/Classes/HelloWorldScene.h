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
   cocos2d::Animate _animate;
   cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation(const char* format, int count);
   cocos2d::Animation* createAnimation(std::string prefixName, int pFrameOrder, float delayTime);
};

#endif // __HELLOWORLD_SCENE_H__
