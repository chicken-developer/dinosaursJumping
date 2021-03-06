#pragma once
#include "cocos2d.h"
USING_NS_CC;

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
	
	Sprite* spCactus_01;
	Sprite* spCactus_02;
	Sprite* spCactus_03;
	Sprite* spCactus_04;
	Sprite* spCactus_05;
	Vector<Sprite*> listCactus;

	Label* lbScore;
	Sprite* spHighScoreIcon;
	Label* lbHighScore;
	Label* lbTapToJump;
	Label* lbReadyToRun;
	Label* lbPlayAgain;

	Vector<SpriteFrame*> getAnimation(const char* format, int count);
public:
	void addCactusToVector();
	

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
	void addHighScorelabel(Scene* scene, int score);
	void addTapToJumpLabel(Scene* scene);
	void addReadyToRunLabel(Scene* scene); 
	void addPlayAgaintLabel(Scene* scene);
	static Sprites* getInstance();

};