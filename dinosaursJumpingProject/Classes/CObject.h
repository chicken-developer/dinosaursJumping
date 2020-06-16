#ifndef __COBJECT_H__
#define __COBJECT_H__
#include "cocos2d.h"
class CObject: public cocos2d::Node{
public:
	CObject();
	virtual bool init();
	virtual  void updateObject(float deltaTime);
	virtual void run(float deltaTime);

	cocos2d::Rect getRect();
	virtual void createPhysicBody(bool isDynamic = true, bool isRotationEnable = true);

	virtual void onCollisionEnter(CObject* gameObject){}
	virtual void onCollisionExit(CObject* gameObject){}
	virtual void onCollisionPreEnter(CObject* gameObject){}
	virtual void onCollisionPostExit(CObject* gameObject);
protected:
	bool _isAlive;
};

#endif

