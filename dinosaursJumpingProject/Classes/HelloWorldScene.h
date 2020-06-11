#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "InfiniteParallaxNode.h"
class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    bool onPhysicContact(PhysicsContact& contact);
    void changeAnimation(cocos2d::Animate* newAnimate);
    float randomValueBetween(float num1, float num2);
	
    virtual bool init();
    void update(float deltaTime);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    bool OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
   InfiniteParallaxNode* backgroundElements;
   void addPhysicWall();
   PhysicsWorld* worldPhysics;
   void setPhysicWorld(PhysicsWorld* m_world) {
       worldPhysics = m_world;
   }
};

#endif // __HELLOWORLD_SCENE_H__
