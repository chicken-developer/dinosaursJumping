#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "InfiniteParallaxNode.h"
class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    void changeAnimation(cocos2d::Animate* newAnimate);
    cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation(const char* format, int count);
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
   cocos2d::Sprite* dinoSprite;

	
   cocos2d::Sprite* handSprite;
   cocos2d::Sprite* spGameLogo;
   cocos2d::Sprite* spGameTitle;
   cocos2d::Sprite* ground;
   cocos2d::Label* tapToJump;
	//Dino animation
   cocos2d::Animation* idleAnim;
   cocos2d::Animation* jumpAnim;
   cocos2d::Animation* runAnim;
	//Dino action animation;
   cocos2d::Animate* Idle();
   cocos2d::Animate* Run();
   cocos2d::Animate* Jump();

};

#endif // __HELLOWORLD_SCENE_H__
