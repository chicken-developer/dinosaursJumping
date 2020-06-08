#include  "Helper.cpp"
#include "HelloWorldScene.h"
#include  "Sprites.h"
#include "Character.h"

USING_NS_CC;

Scene* HelloWorld::createScene(){
    return HelloWorld::create();
}

bool HelloWorld::init(){
   
    if ( !Scene::init() ){
        return false;
    }

	
    SpriteBatchNode* spriteNode = SpriteBatchNode::create("Textures.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Textures.plist");

    Sprites::getSprite()->addHand(this);
    Sprites::getSprite()->addGround(this);
    Sprites::getSprite()->addHighScoreIcon(this);
    Sprites::getSprite()->addHighScorelabel(this);
    Sprites::getSprite()->addScoreIcon(this);
    Sprites::getSprite()->addScoreLabel(this);
    Sprites::getSprite()->addLogoVTC(this);
    Sprites::getSprite()->addRoad_01(this);
    Sprites::getSprite()->addRoad_02(this);
    Sprites::getSprite()->addTitleStart(this);
    Sprites::getSprite()->addTitleGG(this);
    Sprites::getSprite()->addTapToJumpLabel(this);

    Character::myCharacter()->addDino(this);
	
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::OnTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    backgroundElements = InfiniteParallaxNode::create();
    unsigned int treesQuantity = 10;
    for(unsigned int i = 0; i < treesQuantity; i++){
        auto tree = Sprite::createWithSpriteFrameName("cactus_3.png");
        tree->setAnchorPoint(Point::ZERO);
       // tree->setScale(randomValueBetween (0.5, 0.75));
        backgroundElements->addChild(
			tree,
			-4,
			Point(0.5, 1),
			Point(visibleSize.width / (treesQuantity - 5) * (i + 1) + 30,
			55));
    }
     addChild(backgroundElements, 2);
	 schedule(schedule_selector(HelloWorld::update), 0.01);
	

	return true;
}

void HelloWorld::update(float deltaTime){
   Point scrollDecrement = Point(5, 0); 
	backgroundElements->setPosition(backgroundElements->getPosition() - scrollDecrement);
	backgroundElements->updatePosition();
}
//Touch Event
bool HelloWorld::OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
    Character::myCharacter()->changeAnimate(Character::myCharacter()->Jump());
    removeChild(Sprites::getSprite()->lbTapToJump);
   // removeChild(tapToJump);
  //  removeChild(spGameTitle);
  //  removeChild(spGameLogo);
  	return true;
}

float HelloWorld::randomValueBetween(float low, float high){
	return (((float)rand() / RAND_MAX) * (high - low)) + low;
}

void HelloWorld::menuCloseCallback(Ref* pSender){
    Director::getInstance()->end();
}
