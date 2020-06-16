#include "Sprites.h"
#include "Definetions.h"
#include "Helper.h"
Sprites* Sprites::_instance = nullptr;

Sprites* Sprites::getInstance() {
	if (_instance == nullptr) {
		_instance = new Sprites();
	}
	return _instance;
}

Vector<SpriteFrame*> Sprites::getAnimation(const char* format, int count) {
	auto spritecache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> animFrames;
	char str[100];
	for (int i = 1; i <= count; i++) {
		sprintf(str, format, i);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}
	return animFrames;
}

static void problemLoading(const char* filename) {
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


void Sprites::addHand(Scene* scene){
	Vector<SpriteFrame*> handFrames = getAnimation("hand_%d.png", 2);
	spHand = Sprite::createWithSpriteFrame(handFrames.front());
	spHand->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	spHand->setPosition(Helper::getHelpFuncs()->getOrigin().x + Helper::getHelpFuncs()->getVisibleSize().width / 2 + 20,
						Helper::getHelpFuncs()->getOrigin().y + GROUND_HEIGHT + 10);
	scene->addChild(spHand);
	auto handAnim = Animation::createWithSpriteFrames(handFrames, 1.0f / 2);
	spHand->runAction(RepeatForever::create(Animate::create(handAnim)));
}

void Sprites::addLogoVTC(Scene* scene){
	spLogoVTC = Sprite::createWithSpriteFrameName("logo-vtca-xanh-duong.png");
	if (spLogoVTC == nullptr) {
		problemLoading("Sprite Game Logo");
	}

	else {
		spLogoVTC->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
		spLogoVTC->setScale(1.2);
		spLogoVTC->setPosition(Helper::getHelpFuncs()->getOrigin().x + Helper::getHelpFuncs()->getVisibleSize().width / 2,
					   		   Helper::getHelpFuncs()->getOrigin().y + Helper::getHelpFuncs()->getVisibleSize().height);
		scene->addChild(spLogoVTC, 2);
	}

}

void Sprites::addTitleStart(Scene* scene){
	spTitleStart = Sprite::createWithSpriteFrameName("title.png");
	if (spTitleStart == nullptr) {
		problemLoading("Sprite Game Title");
	}

	else {
		spTitleStart->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
		spTitleStart->setScale(1.2);
		spTitleStart->setPosition(Helper::getHelpFuncs()->getOrigin().x + Helper::getHelpFuncs()->getVisibleSize().width / 2,
							   	  Helper::getHelpFuncs()->getOrigin().y + Helper::getHelpFuncs()->getVisibleSize().height - 200);
		scene->addChild(spTitleStart, 2);
	}
}

void Sprites::addCactusToVector() {

	spCactus_01 = Sprite::createWithSpriteFrameName("cactus_1.png");
	if (spCactus_01 == nullptr) {
		problemLoading("Sprite Cactus 1");
	}
	else {
		spCactus_01->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		spCactus_01->setScale(1.2);
		spCactus_01->setPosition(Helper::getHelpFuncs()->getVisibleSize().width - 10, GROUND_HEIGHT);
		auto cactusBody = PhysicsBody::createBox(Size(spCactus_01->getContentSize()));
		cactusBody->setDynamic(false);
		cactusBody->setRotationEnable(false);
		cactusBody->setContactTestBitmask(0x000001);
		spCactus_01->setPhysicsBody(cactusBody);
		spCactus_01->setTag(TYPE_CACTUS);
		listCactus.pushBack(spCactus_01);
	}

	spCactus_02 = Sprite::createWithSpriteFrameName("cactus_2.png");
	if (spCactus_02 == nullptr) {
		problemLoading("Sprite Cactus 2");
	}
	else {
		spCactus_02->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		spCactus_02->setScale(1.2);
		spCactus_02->setPosition(Helper::getHelpFuncs()->getVisibleSize().width - 1010, GROUND_HEIGHT);
		auto cactusBody = PhysicsBody::createBox(Size(spCactus_02->getContentSize()));
		cactusBody->setContactTestBitmask(0x000001);
		cactusBody->setDynamic(false);
		cactusBody->setRotationEnable(false);
		spCactus_02->setPhysicsBody(cactusBody);
		spCactus_02->setTag(TYPE_CACTUS);
		listCactus.pushBack(spCactus_02);
	}

	spCactus_03 = Sprite::createWithSpriteFrameName("cactus_3.png");
	if (spCactus_03 == nullptr) {
		problemLoading("Sprite Cactus 3");
	}
	else {
		spCactus_03->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		spCactus_03->setScale(1.2);
		spCactus_03->setPosition(Helper::getHelpFuncs()->getVisibleSize().width - 2010,GROUND_HEIGHT);
		auto cactusBody = PhysicsBody::createBox(Size(spCactus_03->getContentSize()));
		cactusBody->setContactTestBitmask(0x000001);
		spCactus_03->setPhysicsBody(cactusBody);
		cactusBody->setDynamic(false);
		cactusBody->setRotationEnable(false);
		spCactus_03->setTag(TYPE_CACTUS);
		listCactus.pushBack(spCactus_03);
	}

	spCactus_04 = Sprite::createWithSpriteFrameName("cactus_4.png");
	if (spCactus_04 == nullptr) {
		problemLoading("Sprite Cactus 4");
	}
	else {
		spCactus_04->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		spCactus_04->setScale(1.2);
		spCactus_04->setPosition(Helper::getHelpFuncs()->getVisibleSize().width - 3010, GROUND_HEIGHT);
		auto cactusBody = PhysicsBody::createBox(Size(spCactus_04->getContentSize()));
		cactusBody->setContactTestBitmask(0x000001);
		cactusBody->setDynamic(false);
		cactusBody->setRotationEnable(false);
		spCactus_04->setPhysicsBody(cactusBody);
		spCactus_04->setTag(TYPE_CACTUS);
		listCactus.pushBack(spCactus_04);
	}

	spCactus_05 = Sprite::createWithSpriteFrameName("cactus_5.png");
	if (spCactus_05 == nullptr) {
		problemLoading("Sprite Cactus 5");
	}
	else {
		spCactus_05->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		spCactus_05->setScale(1.2);
		spCactus_05->setPosition(Helper::getHelpFuncs()->getVisibleSize().width - 4010, GROUND_HEIGHT);
		auto cactusBody = PhysicsBody::createBox(Size(spCactus_05->getContentSize()));
		cactusBody->setContactTestBitmask(0x000001);
		spCactus_05->setPhysicsBody(cactusBody);
		cactusBody->setDynamic(false);
		cactusBody->setRotationEnable(false);
		spCactus_05->setTag(TYPE_CACTUS);
		listCactus.pushBack(spCactus_05);
	}

}


void Sprites::addGround(Scene* scene){
	
}

void Sprites::addRoad_01(Scene* scene){
	spRoad_01 = Sprite::createWithSpriteFrameName("road_1.png");
	if (spRoad_01 == nullptr) {
		problemLoading("Sprite Road 1");
	}
	else {
		spRoad_01->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
		spRoad_01->setPosition(0, GROUND_HEIGHT);
		scene->addChild(spRoad_01);
	}
}

void Sprites::addRoad_02(Scene* scene){
	spRoad_02 = Sprite::createWithSpriteFrameName("road_2.png");
	if (spRoad_02 == nullptr) {
		problemLoading("Sprite Road 2");
	}
	else {
		spRoad_02->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
		spRoad_02->setPosition(spRoad_01->getPositionX() + spRoad_01->getContentSize().width - 5,
							   GROUND_HEIGHT);
		scene->addChild(spRoad_02);
	}
}

void Sprites::addTitleGG(Scene* scene){
	 spTitleGG = Sprite::createWithSpriteFrameName("gameover.png");
	if (spTitleGG == nullptr) {
		problemLoading("Sprite Game Over");
	}
	else {
		spTitleGG->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
		spTitleGG->setPosition(Helper::getHelpFuncs()->getOrigin().x + Helper::getHelpFuncs()->getVisibleSize().width / 2,
							   Helper::getHelpFuncs()->getOrigin().y + Helper::getHelpFuncs()->getVisibleSize().height - TITLE_HIDDEN_Y);
		scene->addChild(spTitleGG);
	}
}

void Sprites::addScoreIcon(Scene* scene){
	spScoreIcon = Sprite::createWithSpriteFrameName("scoreicon.png");
	if (spScoreIcon == nullptr) {
		problemLoading("Sprite Score Icon");
	}
	else {
		spScoreIcon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
		spScoreIcon->setScale(1.5);
		spScoreIcon->setPosition(Helper::getHelpFuncs()->getOrigin().x + Helper::getHelpFuncs()->getVisibleSize().width - 10,
								 Helper::getHelpFuncs()->getOrigin().y + Helper::getHelpFuncs()->getVisibleSize().height - 30);
		scene->addChild(spScoreIcon);
	}

}

void Sprites::addScoreLabel(Scene* scene){
	lbScore = Label::createWithTTF("00", "fonts/score.ttf", 50, Size::ZERO);
	if (lbScore == nullptr) {
		problemLoading("Label High Score");
	}
	else {
		lbScore->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
		lbScore->setPosition(Helper::getHelpFuncs()->getOrigin().x + Helper::getHelpFuncs()->getVisibleSize().width - 100,
							 Helper::getHelpFuncs()->getOrigin().y + Helper::getHelpFuncs()->getVisibleSize().height - 30);
		scene->addChild(lbScore);
	}
}

void Sprites::addHighScoreIcon(Scene* scene){
	spHighScoreIcon = Sprite::createWithSpriteFrameName("highscoreicon.png");
	if (spHighScoreIcon == nullptr) {
		problemLoading("Sprite High Score");
	}
	else {
		spHighScoreIcon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
		spHighScoreIcon->setScale(2.0);
		spHighScoreIcon->setPosition(Helper::getHelpFuncs()->getOrigin().x + 45,
									 Helper::getHelpFuncs()->getOrigin().y + Helper::getHelpFuncs()->getVisibleSize().height - 10);
		scene->addChild(spHighScoreIcon);
	}
}

void Sprites::addHighScorelabel(Scene* scene){
	lbHighScore = Label::createWithTTF("120", "fonts/score.ttf", 50, Size::ZERO);
	if (lbHighScore == nullptr) {
		problemLoading("Label High Score");
	}
	else {
		lbHighScore->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
		lbHighScore->setPosition(Helper::getHelpFuncs()->getOrigin().x + 10,
								 Helper::getHelpFuncs()->getOrigin().y + Helper::getHelpFuncs()->getVisibleSize().height - 100);
		scene->addChild(lbHighScore);
	}
}

void Sprites::addTapToJumpLabel(Scene* scene){
	lbTapToJump = Label::createWithTTF("TAP TO JUMP", "fonts/score.ttf", 50, Size::ZERO);
	if (lbTapToJump == nullptr) {
		problemLoading("Label Tap To Jump");
	}
	else {
		lbTapToJump->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		lbTapToJump->setPosition(Helper::getHelpFuncs()->getOrigin().x + Helper::getHelpFuncs()->getVisibleSize().width / 2 - 20,
								 Helper::getHelpFuncs()->getOrigin().y + GROUND_HEIGHT + 150);
		scene->addChild(lbTapToJump);
	}
}

void Sprites::addReadyToRunLabel(Scene* scene){
	lbReadyToRun = Label::createWithTTF("READY TO RUN", "fonts/score.ttf", 100, Size::ZERO);
	if (lbReadyToRun == nullptr) {
		problemLoading("Label ready to run");
	}
	else {
		lbReadyToRun->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		lbReadyToRun->setPosition(Helper::getHelpFuncs()->getOrigin().x + Helper::getHelpFuncs()->getVisibleSize().width / 2,
								 Helper::getHelpFuncs()->getOrigin().y + GROUND_HEIGHT + 500);
		scene->addChild(lbReadyToRun);
	}
}

