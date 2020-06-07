

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
    SpriteBatchNode* spriteNode = SpriteBatchNode::create("Textures.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Textures.plist");

	//Dinosaurs animation
    Vector<SpriteFrame*> frames = getAnimation("Idle (%d).png", 10);
    dinoSprite = Sprite::createWithSpriteFrame(frames.front());
    dinoSprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
    dinoSprite->setScale(0.25);
    dinoSprite->setPosition(origin.x + DINO_X,
							origin.y + GROUND_HEIGHT - 8);
    this->addChild(dinoSprite);
    idleAnim = Animation::createWithSpriteFrames(frames, 1.0f / 10);
    dinoSprite->runAction(RepeatForever::create(Animate::create(idleAnim)));

    Vector<SpriteFrame*> handFrames = getAnimation("hand_%d.png", 2);
    handSprite = Sprite::createWithSpriteFrame(handFrames.front());
    handSprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	handSprite->setPosition(origin.x + visibleSize.width/2,
                            origin.y + GROUND_HEIGHT + 10);
    this->addChild(handSprite);
    auto handAnim = Animation::createWithSpriteFrames(handFrames, 1.0f / 2);
    handSprite->runAction(RepeatForever::create(Animate::create(handAnim)));
	
	//Jump when touch animation
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::OnTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

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
    
   //Game title
    spGameTitle = Sprite::createWithSpriteFrameName("title.png");
   if(spGameTitle == nullptr){
       problemLoading("Sprite Game Title");
   }
      
   else{
       spGameTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
       spGameTitle->setScale(0.5);
       spGameTitle->setPosition(origin.x + visibleSize.width/ 2,
                                origin.y + visibleSize.height - 70);
       this->addChild(spGameTitle,2);
   }

	//Game Logo
    spGameLogo = Sprite::createWithSpriteFrameName("logo-vtca-xanh-duong.png");
   if (spGameLogo == nullptr) {
       problemLoading("Sprite Game Logo");
   }

   else {
       spGameLogo->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
       spGameLogo->setScale(0.5);
       spGameLogo->setPosition(origin.x + visibleSize.width / 2,
                               origin.y + visibleSize.height);
       this->addChild(spGameLogo, 2);
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
      // this->addChild(spGameOver);
   }
	//Score Icon
   auto spScoreIcon = Sprite::createWithSpriteFrameName("scoreicon.png");
   if (spScoreIcon == nullptr) {
       problemLoading("Sprite Score Icon");
   }
   else {
       spScoreIcon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
       spScoreIcon->setScale(1.5);
       spScoreIcon->setPosition(origin.x + visibleSize.width - 10,
                                origin.y + visibleSize.height - 10);
       this->addChild(spScoreIcon);
   }

	//Score Label
        //Label High Score
   auto labelScore = Label::createWithTTF("00", "fonts/score.ttf", 30, Size::ZERO);
   if (labelScore == nullptr) {
       problemLoading("Label High Score");
   }
   else {
       labelScore->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
       labelScore->setPosition(origin.x + visibleSize.width - 80,
                               origin.y + visibleSize.height - 10);
       this->addChild(labelScore);
   }

	//HighScore Icon
   auto spHighScoreIcon = Sprite::createWithSpriteFrameName("highscoreicon.png");
   if (spHighScoreIcon == nullptr) {
       problemLoading("Sprite High Score");
   }
   else {
       spHighScoreIcon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
       spHighScoreIcon->setScale(1.5);
       spHighScoreIcon->setPosition(origin.x + 35,
           origin.y + visibleSize.height - 10);
        this->addChild(spHighScoreIcon);
   }
	//Label High Score
   auto labelHighScore = Label::createWithTTF("120", "fonts/score.ttf", 30, Size::ZERO);
	if (labelHighScore == nullptr) {
       problemLoading("Label High Score");
   }
   else {
        labelHighScore->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
        labelHighScore->setPosition(origin.x + 10,
                                    origin.y + visibleSize.height - 50);
        this->addChild(labelHighScore);
   }
	//taptojump label
    tapToJump = Label::createWithTTF("TAP TO JUMP", "fonts/score.ttf", 50, Size::ZERO);
    if (tapToJump == nullptr) {
        problemLoading("Label Tap To Jump");
    }
    else {
        tapToJump->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
        tapToJump->setPosition(origin.x + visibleSize.width / 2,
                               origin.y + GROUND_HEIGHT + 80);
        this->addChild(tapToJump);
    }


    backgroundElements = InfiniteParallaxNode::create();

   //Add rock
    // unsigned int cactusQuantity = 7;
    // for(unsigned int i = 0; i < cactusQuantity; i++){
    //     auto rock = Sprite::createWithSpriteFrameName("cactus_1.png");
    //     rock->setAnchorPoint(Point::ZERO);
    //     rock->setScale(randomValueBetween(0.6, 0.75));
    //     backgroundElements->addChild(rock,
	// 		randomValueBetween(-10, -6),
	// 		Point(0.95, 1.0),
	// 		Point(
	// 		(visibleSize.width / 5) * (i + 1) + randomValueBetween(0, 100),
	// 		ground->getContentSize().height - 5));
    // }
    // //Add tree
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
    changeAnimation(HelloWorld::Jump());
    removeChild(handSprite);
    removeChild(tapToJump);
    removeChild(spGameTitle);
    removeChild(spGameLogo);
  	return true;
}

void HelloWorld::changeAnimation(Animate* newAnimate){
    dinoSprite->stopAllActions();
    newAnimate->retain();
    dinoSprite->runAction(newAnimate);
    dinoSprite->runAction(RepeatForever::create(Animate::create(idleAnim)));
 
}
// void HelloWorld::changeAnimation(Animate* newAnimate){
//     dinoSprite->stopAllActions();
//     newAnimate->retain();
//     dinoSprite->runAction(RepeatForever::create(newAnimate));
// }

cocos2d::Animate* HelloWorld::Idle(){
    Vector<SpriteFrame*> frames = getAnimation("Idle (%d).png", 10);
    idleAnim = Animation::createWithSpriteFrames(frames, 1.0f / 10);
    auto animate = Animate::create(idleAnim);
    return animate;
   }

cocos2d::Animate* HelloWorld::Jump(){
    Vector<SpriteFrame*> frames = getAnimation("Jump (%d).png", 12);
    jumpAnim = Animation::createWithSpriteFrames(frames, 1.0f / 12);
    auto animate = Animate::create(jumpAnim);
    return animate;
   }

cocos2d::Animate* HelloWorld::Run(){
    Vector<SpriteFrame*> frames = getAnimation("Run (%d).png", 8);
    runAnim = Animation::createWithSpriteFrames(frames, 1.0f / 8);
	auto animate = Animate::create(runAnim);
    return animate;
}


cocos2d::Vector<SpriteFrame*> HelloWorld::getAnimation(const char* format, int count) {
    auto spriteCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> animFrames;
    char str[100];
    for (int i = 1; i <= count; i++) {
        sprintf(str, format, i);
        animFrames.pushBack(spriteCache->getSpriteFrameByName(str));
    }
    return animFrames;
}

float HelloWorld::randomValueBetween(float low, float high){
	return (((float)rand() / RAND_MAX) * (high - low)) + low;
}

void HelloWorld::menuCloseCallback(Ref* pSender){
    Director::getInstance()->end();
}
