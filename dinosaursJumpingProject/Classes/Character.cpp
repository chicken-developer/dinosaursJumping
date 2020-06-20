#include "Character.h"
#include "Helper.h"


Character* Character::_Character = NULL;
Character* Character::getInstance() {
	if (Character::_Character == nullptr) {
		_Character = new Character();
	}
	return _Character;
}

void Character::addDino(Scene* scene){
	Vector<SpriteFrame*> frames = getAnimation("Idle (%d).png",1, 10);
	spDino = Sprite::createWithSpriteFrame(frames.front());
	spDino->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	spDino->setScale(0.25);
	spDino->setPosition(Helper::getHelpFuncs()->getOrigin().x + DINO_X - 10,
		Helper::getHelpFuncs()->getOrigin().y + GROUND_HEIGHT + 100);
	dinoPhysicBody->setPositionOffset(Vec2(-50, 0));
	dinoPhysicBody->setRotationEnable(false);
	spDino->setTag(TYPE_DINO);
	spDino->setPhysicsBody(dinoPhysicBody);
	dinoPhysicBody->setContactTestBitmask(0x000001);
	scene->addChild(spDino);
	idleAnim = Animation::createWithSpriteFrames(frames, 1.0f / 10);
	spDino->runAction(RepeatForever::create(Animate::create(idleAnim)));
}

Vector<SpriteFrame*> Character::getAnimation(const char* format,int firstIndex, int count){
	auto spritecache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> animFrames;
	char str[100];
	for (int i = firstIndex; i <= count; i++) {
		sprintf(str, format, i);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}
	return animFrames;
}

void Character::changeAnimate(int AnimationID){
	spDino->stopAllActions();
	switch (AnimationID){
	case DINOA::IDLE:
		currentAnimate = Idle();
		break;
	case DINOA::WALK:
		currentAnimate = Walk();
		break;
	case DINOA::RUN:
		currentAnimate = Run();
		break;
	case DINOA::JUMP:
		currentAnimate = Jump();
		break;
	case DINOA::DIE:
		currentAnimate = DieForever();
			break;
	default:
		break;
		
	}
	spDino->runAction(RepeatForever::create(currentAnimate));
}

cocos2d::Animate* Character::Idle() {
	Vector<SpriteFrame*> frames = getAnimation("Idle (%d).png",1, 10);
	idleAnim = Animation::createWithSpriteFrames(frames, 1.0f / 10);
	auto animate = Animate::create(idleAnim);
	return animate;
}

cocos2d::Animate* Character::Walk() {
	Vector<SpriteFrame*> frames = getAnimation("Walk (%d).png",1, 10);
	walkAnim = Animation::createWithSpriteFrames(frames, 1.0f / 10);
	auto animate = Animate::create(walkAnim);
	return animate;
}


cocos2d::Animate* Character::Run() {
	Vector<SpriteFrame*> frames = getAnimation("Run (%d).png",1, 8);
	runAnim = Animation::createWithSpriteFrames(frames, 1.0f / 8);
	auto animate = Animate::create(runAnim);
	return animate;
}

cocos2d::Animate* Character::Jump() {
	Vector<SpriteFrame*> frames = getAnimation("Jump (%d).png",1, 12);
	jumpAnim = Animation::createWithSpriteFrames(frames, 2.0f / 12);
	auto animate = Animate::create(jumpAnim);
	return animate;
}

cocos2d::Animate* Character::Die() {
	Vector<SpriteFrame*> frames = getAnimation("Dead (%d).png",1, 8);
	dieAnim = Animation::createWithSpriteFrames(frames, 1.0f / 8);
	auto animate = Animate::create(dieAnim);
	return animate;
}

cocos2d::Animate* Character::DieForever() {
	Vector<SpriteFrame*> frames = getAnimation("Dead (%d).png", 5, 8);
	dieForever = Animation::createWithSpriteFrames(frames, 1.0f / 4);
	auto animate = Animate::create(dieForever);
	return animate;
}


