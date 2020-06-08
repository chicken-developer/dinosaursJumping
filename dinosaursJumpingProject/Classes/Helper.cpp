#include  "cocos2d.h"
USING_NS_CC;

auto visibleSize = Director::getInstance()->getVisibleSize();
Vec2 origin = Director::getInstance()->getVisibleOrigin();

Vector<SpriteFrame*> getAnimation(const char* format, int count) {
	auto spriteCache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> animFrames;
	char str[100];
	for (int i = 1; i <= count; i++) {
		sprintf(str, format, i);
		animFrames.pushBack(spriteCache->getSpriteFrameByName(str));
	}
	return animFrames;
}
