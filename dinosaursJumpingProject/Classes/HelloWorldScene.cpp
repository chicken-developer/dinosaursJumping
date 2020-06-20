#include  "Helper.h"
#include "HelloWorldScene.h"
#include  "Sprites.h"
#include "Character.h"

USING_NS_CC;

Scene* HelloWorld::createScene(){
    auto scene = Scene::createWithPhysics();
    Vect gravity(0.0f, -700.0f);
    scene->getPhysicsWorld()->setGravity(gravity);
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); 
    auto layer = HelloWorld::create();
    layer->setPhysicWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

void HelloWorld::addPhysicWall() {
    auto bodyWall = PhysicsBody::createEdgeBox(Size(DEVICE_WIDTH ,DEVICE_HEIGHT - GROUND_HEIGHT), PHYSICSBODY_MATERIAL_DEFAULT,3);
	bodyWall->setRotationOffset(-90);
  	auto wallNode = Node::create();
    wallNode->setPosition(Vec2(DEVICE_WIDTH/ 2,DEVICE_HEIGHT/ 2 + GROUND_HEIGHT - 175));
    wallNode->setPhysicsBody(bodyWall);
    bodyWall->setContactTestBitmask(0x000001);
    this->addChild(wallNode);
    wallNode->setTag(TYPE_WALL);
}


bool HelloWorld::init() {

    if (!Scene::init()) {
        return false;
    }

    addPhysicWall();
    SpriteBatchNode* spriteNode = SpriteBatchNode::create("Textures.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Textures.plist");

    Sprites::getInstance()->addHand(this);
    Sprites::getInstance()->addGround(this);
    Sprites::getInstance()->addHighScoreIcon(this);
    Sprites::getInstance()->addHighScorelabel(this);
    Sprites::getInstance()->addScoreIcon(this);
    Sprites::getInstance()->addScoreLabel(this);
    Sprites::getInstance()->addLogoVTC(this);
    Sprites::getInstance()->addRoad_01(this);
    Sprites::getInstance()->addRoad_02(this);
    Sprites::getInstance()->addTitleStart(this);
   // Sprites::getInstance()->addTitleGG(this);
    Sprites::getInstance()->addTapToJumpLabel(this);
    Character::getInstance()->addDino(this);
    Sprites::getInstance()->addCactusToVector();
        for(int i = 0; i < Sprites::getInstance()->listCactus.size(); i ++){
            this->addChild(Sprites::getInstance()->listCactus.at(i));
        }
   
	//Touch event for handle touch on screen
    auto* touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

    //Event listener for handle collision
    EventListenerPhysicsContact* contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    contactListener->onContactPreSolve = CC_CALLBACK_2(HelloWorld::onContactPreSolve, this);
    contactListener->onContactPostSolve = CC_CALLBACK_2(HelloWorld::onContactPostSolve, this);
    contactListener->onContactSeparate = CC_CALLBACK_1(HelloWorld::onContactSeperate, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener,this);

    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float deltaTime){
	if(IsPlaying == true){
        //Handle Dino speed & animation
        timeToRun -= deltaTime;
        if (timeToRun < 0) {
            timeToRun = 0;
            gameSpeed = 250;
        }
        for (int i = 0; i < Sprites::getInstance()->listCactus.size(); i++) {
            // if(Sprites::getInstance()->listCactus.at(i)->getPosition().x >= Helper::getHelpFuncs()->getVisibleSize().width){
            Sprites::getInstance()->listCactus.at(i)->setPosition(Vec2(
                Sprites::getInstance()->listCactus.at(i)->getPosition().x - gameSpeed * deltaTime, GROUND_HEIGHT
            ));
        }
        for (int i = 0; i < Sprites::getInstance()->listCactus.size(); i++) {
            if (Sprites::getInstance()->listCactus.at(i)->getPosition().x <= 0) {
                timeAddCatus -= deltaTime;
                if (timeAddCatus <= 0) {
                    Sprites::getInstance()->listCactus.at(i)->setPosition(Helper::getHelpFuncs()->getVisibleSize().width + randomValueBetween(10, 200), GROUND_HEIGHT);
                    timeAddCatus = 8;
                    currentScore += 1;
                    Sprites::getInstance()->lbScore->setString(std::to_string(currentScore));
                }

            }
        }
	}
  
}
/* Touchs event help function*/
bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
    IsPlaying = true;
    removeChild(Sprites::getInstance()->spHand);
    removeChild(Sprites::getInstance()->spLogoVTC);
    removeChild(Sprites::getInstance()->spTitleStart);
    removeChild(Sprites::getInstance()->lbTapToJump);
    Character::getInstance()->changeAnimate(DINOA::JUMP);
    Vect offset = Vect(1.0f, 0.0f);
    Vect force = Vect(0.0f, 10001000.0f);
    if(timeToRun <= 4) {
        Sprites::getInstance()->addReadyToRunLabel(this);
    }
    if(timeToRun <= 0) {
     removeChild(Sprites::getInstance()->lbReadyToRun); 
    }
    Character::getInstance()->dinoPhysicBody->applyForce(force, offset);
 	return true;
}

 bool HelloWorld::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event){
     return true;
 }
 bool HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
    return true;
 }

/* Physics event help function*/
bool HelloWorld::onContactBegin(PhysicsContact& contact) {
    auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
    auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
    int tagA = spriteA->getTag();                                     
    int tagB = spriteB->getTag();
	
    //Dino vs ground
    if ( (tagA == TYPE_DINO && tagB == TYPE_WALL) || (tagA == TYPE_WALL && tagB == TYPE_DINO)){
        if(tagA == TYPE_DINO && timeToRun > 0){
            if (IsPlaying == true) Character::getInstance()->changeAnimate(DINOA::WALK);
            else Character::getInstance()->changeAnimate(DINOA::IDLE);
        }
        if(tagB == TYPE_DINO && timeToRun > 0){
            if (IsPlaying == true) Character::getInstance()->changeAnimate(DINOA::WALK);
            else Character::getInstance()->changeAnimate(DINOA::IDLE);
        }

        if (tagA == TYPE_DINO && timeToRun <= 0) {
            Character::getInstance()->changeAnimate(DINOA::RUN);
        }
        if (tagB == TYPE_DINO && timeToRun <= 0) {
            Character::getInstance()->changeAnimate(DINOA::RUN);
        }
    }

    //Dino vs cactus
    if ( (tagA == TYPE_DINO && tagB == TYPE_CACTUS) || (tagA == TYPE_CACTUS && tagB == TYPE_DINO)){
        if(tagA == TYPE_DINO ){
            Character::getInstance()->changeAnimate(DINOA::DIE);
            IsPlaying = false;
        }
        if(tagB == TYPE_DINO ){
            Character::getInstance()->changeAnimate(DINOA::DIE);
            IsPlaying = false;
        }
    }

    return true;
}

bool HelloWorld::onContactPreSolve(PhysicsContact& contact,
    PhysicsContactPreSolve& solve) {
    solve.setRestitution(0);
    return true;
}

void HelloWorld::onContactPostSolve(PhysicsContact& contact, const PhysicsContactPostSolve& solve) {}

void HelloWorld::onContactSeperate(PhysicsContact& contact) {}


/*Another function*/
float HelloWorld::randomValueBetween(float low, float high) {
    return (((float)rand() / RAND_MAX) * (high - low)) + low;
}

void HelloWorld::menuCloseCallback(Ref* pSender) {
    Director::getInstance()->end();
}