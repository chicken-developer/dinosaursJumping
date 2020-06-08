#include "Sprites.h"
#include "Definetions.h"
#include "Helper.cpp"

Sprites* Sprites::_instance = NULL;

Sprites* Sprites::getSprite() {
	if (_instance == nullptr) {
		_instance = new Sprites();
	}
	return _instance;
}


static void problemLoading(const char* filename) {
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


void Sprites::addHand(Scene* scene){
	Vector<SpriteFrame*> handFrames = getAnimation("hand_%d.png", 2);
	spHand = Sprite::createWithSpriteFrame(handFrames.front());
	spHand->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	spHand->setPosition(origin.x + visibleSize.width / 2,
		origin.y + GROUND_HEIGHT + 10);
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
		spLogoVTC->setScale(0.5);
		spLogoVTC->setPosition(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height);
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
		spTitleStart->setScale(0.5);
		spTitleStart->setPosition(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - 70);
		scene->addChild(spTitleStart, 2);
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
		spTitleGG->setPosition(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - TITLE_HIDDEN_Y);
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
		spScoreIcon->setPosition(origin.x + visibleSize.width - 10,
			origin.y + visibleSize.height - 10);
		scene->addChild(spScoreIcon);
	}

}

void Sprites::addScoreLabel(Scene* scene){
	lbScore = Label::createWithTTF("00", "fonts/score.ttf", 30, Size::ZERO);
	if (lbScore == nullptr) {
		problemLoading("Label High Score");
	}
	else {
		lbScore->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
		lbScore->setPosition(origin.x + visibleSize.width - 80,
			origin.y + visibleSize.height - 10);
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
		spHighScoreIcon->setScale(1.5);
		spHighScoreIcon->setPosition(origin.x + 35,
			origin.y + visibleSize.height - 10);
		scene->addChild(spHighScoreIcon);
	}
}

void Sprites::addHighScorelabel(Scene* scene){
	lbHighScore = Label::createWithTTF("120", "fonts/score.ttf", 30, Size::ZERO);
	if (lbHighScore == nullptr) {
		problemLoading("Label High Score");
	}
	else {
		lbHighScore->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
		lbHighScore->setPosition(origin.x + 10,
			origin.y + visibleSize.height - 50);
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
		lbTapToJump->setPosition(origin.x + visibleSize.width / 2,
			origin.y + GROUND_HEIGHT + 80);
		scene->addChild(lbTapToJump);
	}

}
