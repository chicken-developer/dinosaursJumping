

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Definetions.h"
USING_NS_CC;

Scene* HelloWorld::createScene(){
    return HelloWorld::create();
}

static void problemLoading(const char* filename){
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init(){
   
    if ( !Scene::init() ){
        return false;
    }
    //Auto Layout
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    float deviceHeight = MAX(glview->getFrameSize().height, glview->getFrameSize().width);
    float deviceWidth = MIN(glview->getFrameSize().height, glview->getFrameSize().width);
    deviceHeight = deviceHeight / deviceWidth * 600;
    deviceWidth = 600;

	
    SpriteBatchNode* spriteNode = SpriteBatchNode::create("Textures.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Textures.plist");

 
    //Dinosaurs
    auto spDino = Sprite::createWithSpriteFrameName("dino_1.png");
    if (spDino == nullptr) {
        problemLoading("Sprite Dino");
    }
    else {
        spDino->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
        spDino->setPosition(DINO_X, GROUND_HEIGHT);
        spriteNode->addChild(spDino);
        this->addChild(spriteNode);
    }
    //Dino  Animation
    _animate = Animate::create(HelloWorld::createAnimation("dino_", 2, 0.4));
    _animate->retain();
    spDino->runAction(RepeatForever::create(_animate));

  	
    //Game title
    auto spGameTitle = Sprite::createWithSpriteFrameName("title.png");
    if(spGameTitle == nullptr){
        problemLoading("Sprite Game Title");
    }
    else{
        spGameTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
        spGameTitle->setPosition(origin.x + visibleSize.width /2,
                                 origin.y + visibleSize.height - TITLE_INITIAL_Y);
        this->addChild(spGameTitle,2);
    }

    //Game over sprites
    auto spGameOver = Sprite::createWithSpriteFrameName("gameover.png");
    if(spGameOver == nullptr){
        problemLoading("Sprite Game Over");
    }
    else{
        spGameOver->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
        spGameOver->setPosition(origin.x + visibleSize.width/ 2,
                                origin.y + visibleSize.height - TITLE_HIDDEN_Y);
        this->addChild(spGameOver);
    }

    //Road 1 Sprite
    auto spRoad_1 = Sprite::createWithSpriteFrameName("road_1.png");
    if(spRoad_1 == nullptr){
        problemLoading("Sprite Road 1");
    }
    else{
        spRoad_1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
        spRoad_1->setPosition(0, GROUND_HEIGHT);
        this->addChild(spRoad_1);
    }

    //Road 2 Sprite
    auto spRoad_2 = Sprite::createWithSpriteFrameName("road_2.png");
    if(spRoad_2 == nullptr){
        problemLoading("Sprite Road 2");
    }
    else{
        spRoad_2->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
        spRoad_2->setPosition(spRoad_1->getPositionX() + spRoad_1->getContentSize().width - 5,
                              GROUND_HEIGHT);
        this->addChild(spRoad_2);
    }
    
   
    return true;
}

/*
* Animation
*/
cocos2d::Animation* HelloWorld::createAnimation(std::string prefixName, int pFrameOrder, float delayTime){
    Vector<SpriteFrame*> animFrames;
    for (int i = 1; i <= pFrameOrder; i++) {
        char buffer[20] = { 0 };
        sprintf(buffer, "%d.png", i);
        std::string imgName = prefixName + buffer;
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(imgName);
        animFrames.pushBack(frame);
	}
   Animation* animation = Animation::createWithSpriteFrames(animFrames, delayTime);
   return animation;
}

void HelloWorld::menuCloseCallback(Ref* pSender){
    Director::getInstance()->end();
}
