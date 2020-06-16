#pragma once
#include "cocos2d.h"
#include "Definetions.h"
USING_NS_CC;


class Character : public cocos2d::Sprite {
public:
	static Character* _Character; 
	Sprite* spDino;
	void addDino(Scene* scene);
	Vector<SpriteFrame*> getAnimation(const char* format, int count);
	PhysicsBody* dinoPhysicBody = PhysicsBody::createBox(Size(DINO_WIDTH * 2/3,DINO_HEIGHT));
	Animate* currentAnimate;
	void changeAnimate(int AnimationID );
	cocos2d::Animation* idleAnim;
	cocos2d::Animation* walkAnim;
	cocos2d::Animation* jumpAnim;
	cocos2d::Animation* runAnim;
	cocos2d::Animation* dieAnim;


	cocos2d::Animate* Idle();
	cocos2d::Animate* Walk();
	cocos2d::Animate* Die();

	cocos2d::Animate* Run();
	cocos2d::Animate* Jump();

public:
	static Character* getInstance();
	
};

enum DINOA {
	IDLE,
	RUN,
	JUMP,
	WALK,
	DIE
};
