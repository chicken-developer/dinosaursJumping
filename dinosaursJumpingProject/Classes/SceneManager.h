#ifndef __SCENE_MANAGER_H__
#define __SCEME_MANAGER_H__

#include "cocos2d.h"
#include "CScene.h"
#include "Definetions.h"

enum EScene {
	SPLASH_SCENE,
	MAIN_MENU_SCENE,
	HELLO_WORLD_SCENE,
	GAME_OVER_SCENE,
};

class SceneManager {
protected:
	static SceneManager* _instance;

	SceneManager();
	SceneManager(const SceneManager& other) {};
	virtual ~SceneManager(){}
public:
	static SceneManager* getInstance();
	CScene* createScene(int sceneID);
	CScene* createStartScene();
	CScene* getCurrentScene();

	void replaceScene(int newSceneID);
	void pushScene(int newSceneID);
	void popLastScene();
	void increaseScore();
	void reset();

	CC_SYNTHESIZE_READONLY(int, _score, Score);
	CC_SYNTHESIZE(cocos2d::Label*, _scoreLabel, ScoreLabel);
	
};
#endif
