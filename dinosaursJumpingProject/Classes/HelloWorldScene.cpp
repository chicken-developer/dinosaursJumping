#include  "Helper.h"
#include "HelloWorldScene.h"
#include  "Sprites.h"
#include "Character.h"
#include "Definetions.h"

USING_NS_CC;

Scene* HelloWorld::createScene(){
    auto scene = Scene::createWithPhysics();
   	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    Vect gravity(0.0f, -90.0f);
    scene->getPhysicsWorld()->setGravity(gravity);
    auto layer = HelloWorld::create();
    layer->setPhysicWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}


void HelloWorld::addPhysicWall() {
    auto bodyWall = PhysicsBody::createEdgeBox(Size((Helper::getHelpFuncs()->getOrigin().x + Helper::getHelpFuncs()->getVisibleSize().width),
												    (Helper::getHelpFuncs()->getOrigin().y + Helper::getHelpFuncs()->getVisibleSize().height - GROUND_HEIGHT)),
										       PHYSICSBODY_MATERIAL_DEFAULT,3);
    auto wallNode = Node::create();
    wallNode->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    wallNode->setPosition(Vec2(Helper::getHelpFuncs()->getOrigin().x + Helper::getHelpFuncs()->getVisibleSize().width,
						       Helper::getHelpFuncs()->getOrigin().y + Helper::getHelpFuncs()->getVisibleSize().height));
    wallNode->setPhysicsBody(bodyWall);
    this->addChild(wallNode);
}


bool HelloWorld::init(){
   
    if ( !Scene::init() ){
        return false;
    }

    addPhysicWall();
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
  //  Sprites::getSprite()->addTitleGG(this);
    Sprites::getSprite()->addTapToJumpLabel(this);

    Character::myCharacter()->addDino(this);
	
    

	// //Parallax for catus
 //    backgroundElements = InfiniteParallaxNode::create();
 //    unsigned int cactusQuantity = 10;
 //    for(unsigned int i = 0; i < cactusQuantity; i++){
 //        int randomInt =(int)randomValueBetween(2, 3.5);
 //        auto cactus = Sprite::createWithSpriteFrameName("cactus_" + std::to_string(randomInt) + ".png");
 //        cactus->setAnchorPoint(Point::ZERO);
 //        cactus->setScale(randomValueBetween (1.5, 2.5));
 //        backgroundElements->addChild(
 //                cactus,
 //                0,
 //                Point(0.3, 0.5),
 //                Point(Helper::getHelpFuncs()->getVisibleSize().width,
	// 							 GROUND_HEIGHT));
 //       
 //    }
 //     addChild(backgroundElements, 0);
	//  schedule(schedule_selector(HelloWorld::update), 0.01);

	return true;
}

void HelloWorld::update(float deltaTime){
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::OnTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	
	// Point scrollDecrement = Point(6, 0); 
	// backgroundElements->setPosition(backgroundElements->getPosition() - scrollDecrement);
	// backgroundElements->updatePosition();
    //if (backgroundElements->getPosition().x < Helper::getHelpFuncs()->getVisibleSize().width/ 2) removeChild(backgroundElements);
}

//Touch Event
bool HelloWorld::OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
    Character::myCharacter()->changeAnimate(Character::myCharacter()->Run());
  	return true;
}

float HelloWorld::randomValueBetween(float low, float high){
	return (((float)rand() / RAND_MAX) * (high - low)) + low;
}

void HelloWorld::menuCloseCallback(Ref* pSender){
    Director::getInstance()->end();
}
