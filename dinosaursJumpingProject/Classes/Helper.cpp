#include "Helper.h"

Helper* Helper::_instance = nullptr;

Helper* Helper::getHelpFuncs(){
	if(_instance == nullptr){
		_instance = new Helper();
	}
	return _instance;
}

Size Helper::getVisibleSize(){
	visibleSize = Director::getInstance()->getVisibleSize();
	return visibleSize;
}

Vec2 Helper::getOrigin() {
	origin = Director::getInstance()->getVisibleOrigin();
	return origin;
}

