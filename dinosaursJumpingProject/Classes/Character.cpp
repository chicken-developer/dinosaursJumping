#include "Character.h"
#include "Definetions.h"
#include "Helper.h"

Character* Character::_Character = NULL;
Character* Character::myCharacter() {
	if (Character::_Character == nullptr) {
		_Character = new Character();
	}
	return _Character;
}

void Character::addDino(Scene* scene){
	Vector<SpriteFrame*> frames = getAnimation("Idle (%d).png", 10);
	spDino = Sprite::createWithSpriteFrame(frames.front());
	spDino->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	spDino->setScale(0.25);
	spDino->setPosition(Helper::getHelpFuncs()->getOrigin().x + DINO_X - 100,
		Helper::getHelpFuncs()->getOrigin().y + GROUND_HEIGHT - 8);
	spDino->setPhysicsBody(dinoPhysicBody);
	scene->addChild(spDino);
	idleAnim = Animation::createWithSpriteFrames(frames, 1.0f / 10);
	spDino->runAction(RepeatForever::create(Animate::create(idleAnim)));
}

Vector<SpriteFrame*> Character::getAnimation(const char* format, int count){
	auto spritecache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> animFrames;
	char str[100];
	for (int i = 1; i <= count; i++) {
		sprintf(str, format, i);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}
	return animFrames;
}

void Character::changeAnimate(Animate* newAnimate){
	spDino->stopAllActions();
	newAnimate->retain();
	spDino->runAction(newAnimate);
	spDino->runAction(RepeatForever::create(Animate::create(idleAnim)));
}

cocos2d::Animate* Character::Idle() {
	Vector<SpriteFrame*> frames = getAnimation("Idle (%d).png", 10);
	idleAnim = Animation::createWithSpriteFrames(frames, 1.0f / 10);
	auto animate = Animate::create(idleAnim);
	return animate;
}

cocos2d::Animate* Character::Run() {
	Vector<SpriteFrame*> frames = getAnimation("Run (%d).png", 8);
	runAnim = Animation::createWithSpriteFrames(frames, 1.0f / 8);
	auto animate = Animate::create(runAnim);
	return animate;
}

cocos2d::Animate* Character::Jump() {
	Vector<SpriteFrame*> frames = getAnimation("Jump (%d).png", 12);
	jumpAnim = Animation::createWithSpriteFrames(frames, 1.0f / 12);
	auto animate = Animate::create(jumpAnim);
	return animate;
}


