#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CScene.h"
#include "InfiniteParallaxNode.h"
#include "Definetions.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static Scene* createScene();
    float timeAddCatus = 8;
    float timeToRun = 30;
    int gameSpeed = 150;
    int currentScore = 0;
    float randomValueBetween(float num1, float num2);
    bool IsPlaying = false;
    CREATE_FUNC(HelloWorld);
	
    virtual bool init();
    virtual void update(float deltaTime);
	
    void menuCloseCallback(cocos2d::Ref* pSender);

	
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    bool onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    // Physics Contact Listener.....//
    bool onContactBegin(PhysicsContact& contact);
    bool onContactPreSolve(PhysicsContact& contact,PhysicsContactPreSolve& solve);
    void onContactPostSolve(PhysicsContact& contact,const PhysicsContactPostSolve& solve);
    void onContactSeperate(PhysicsContact& contact);	

private:
   InfiniteParallaxNode* backgroundElements;
   void addPhysicWall();
   PhysicsWorld* worldPhysics;
   void setPhysicWorld(PhysicsWorld* m_world) {
       worldPhysics = m_world;
   }
};

#endif // __HELLOWORLD_SCENE_H__
