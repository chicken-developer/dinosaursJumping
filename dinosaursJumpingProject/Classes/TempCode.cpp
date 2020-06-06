
#include "HelloWorldScene.h"
/*
* Animation functions
*/
cocos2d::Sprite* spDino;
cocos2d::Animation* _animation;
cocos2d::Animation* createAnimation(std::string prefixName, int pFrameOrder, float delayTime);

auto director = Director::getInstance();
auto glview = director->getOpenGLView();
float deviceHeight = MAX(glview->getFrameSize().height, glview->getFrameSize().width);
float deviceWidth = MIN(glview->getFrameSize().height, glview->getFrameSize().width);
deviceHeight = deviceHeight / deviceWidth * 600;
deviceWidth = 600;

cocos2d::Animation* HelloWorld::createAnimation(std::string prefixName, int pFrameOrder, float delayTime) {
    Vector<SpriteFrame*> animFrames;
    for (int i = 1; i <= pFrameOrder; i++) {
        char buffer[20] = { 0 };
        sprintf(buffer, " (%d).png", i);
        std::string imgName = prefixName + buffer;
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(imgName);
        animFrames.pushBack(frame);
    }
    _animation = Animation::createWithSpriteFrames(animFrames, delayTime);
    return _animation;
    //khoapham.vn
}


//Create by tutorial at khoapham.vn //
spDino = Sprite::createWithSpriteFrameName("Idle (1).png");
if (spDino == nullptr) {
    problemLoading("Sprite Dino");
}
else {
    spDino->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
    spDino->setScale(0.25);
    spDino->setPosition(DINO_X,
        GROUND_HEIGHT - 4);
    spriteNode->addChild(spDino);
    this->addChild(spriteNode);
}
auto animate = Animate::create(HelloWorld::createAnimation("Idle", 10, 0.15));
animate->retain();
spDino->runAction(RepeatForever::create(animate));

