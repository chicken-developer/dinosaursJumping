#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Helper{
private:
	static Helper* _instance;
	 Size visibleSize;
	 Vec2 origin;
public:
	Size getVisibleSize();
	Vec2 getOrigin();
	static Helper* getHelpFuncs();
};
