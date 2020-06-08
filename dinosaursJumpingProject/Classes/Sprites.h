#pragma once
#include "cocos2d.h"
USING_NS_CC;
#pragma once

class Sprites{
public:
	static Sprites* _instance;
	Sprite* spHand;
	Sprite* spLogoVTC;
	Sprite* spTitleStart;
	Sprite* spGround;
	Sprite* spRoad_01;
	Sprite* spRoad_02;
	Sprite* spTitleGG;
	Sprite* spScoreIcon;
	Label* lbScore;
	Sprite* spHighScoreIcon;
	Label* lbHighScore;
	Label* lbTapToJump;

	void addHand(Scene* scene);
	void addLogoVTC(Scene* scene);
	void addTitleStart(Scene* scene);
	void addGround(Scene* scene);
	void addRoad_01(Scene* scene);
	void addRoad_02(Scene* scene);
	void addTitleGG(Scene* scene);
	void addScoreIcon(Scene* scene);
	void addScoreLabel(Scene* scene);
	void addHighScoreIcon(Scene* scene);
	void addHighScorelabel(Scene* scene);
	void addTapToJumpLabel(Scene* scene);

public:
	static Sprites* getSprite();
};