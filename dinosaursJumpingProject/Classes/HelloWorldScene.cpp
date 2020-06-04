

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

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Textures.plist");


    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    float deviceHeight = MAX(glview->getFrameSize().height, glview->getFrameSize().width);
    float deviceWidth = MIN(glview->getFrameSize().height, glview->getFrameSize().width);
    deviceHeight = deviceHeight/ deviceWidth * 600;
    deviceWidth = 600;


    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr){
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else{
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        this->addChild(label, 1);
    }

    auto spGameTitle = Sprite::createWithSpriteFrameName("title.png");
    if(spGameTitle == nullptr){
        problemLoading("Sprite Game Title");
    }
    else{
        spGameTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
        spGameTitle->setPosition(origin.x + visibleSize.width /2, origin.y + visibleSize.height - TITLE_INITIAL_Y);
        this->addChild(spGameTitle,2);
    }

    auto spGameOver = Sprite::createWithSpriteFrameName("gameover.png");
    if(spGameOver == nullptr){
        problemLoading("Sprite Game Over");
    }
    else{
        spGameOver->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
        spGameOver->setPosition(deviceWidth/ 2, deviceHeight - TITLE_HIDDEN_Y);
        this->addChild(spGameOver);
    }

    auto spRoad_1 = Sprite::createWithSpriteFrameName("road_1.png");
    if(spRoad_1 == nullptr){
        problemLoading("Sprite Road 1");
    }
    else{
        spRoad_1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
        spRoad_1->setPosition(0, GROUND_HEIGHT);
        this->addChild(spRoad_1);
    }

     auto spRoad_2 = Sprite::createWithSpriteFrameName("road_2.png");
    if(spRoad_2 == nullptr){
        problemLoading("Sprite Road 2");
    }
    else{
        spRoad_2->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
        spRoad_2->setPosition(spRoad_1->getPositionX() + spRoad_1->getContentSize().width - 5, GROUND_HEIGHT);
        this->addChild(spRoad_2);
    }

    auto spDino = Sprite::createWithSpriteFrameName("dino_1.png");
    if(spDino == nullptr){
        problemLoading("Sprite Dino");
    }
    else{
        spDino->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
        spDino->setPosition(DINO_X, GROUND_HEIGHT);
        this->addChild(spDino);
    }



    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender){
    Director::getInstance()->end();
}
