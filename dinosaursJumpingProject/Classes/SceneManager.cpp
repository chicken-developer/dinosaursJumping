#include "SceneManager.h"
#include "HelloWorldScene.h"
USING_NS_CC;

SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager():_score(0),_scoreLabel(nullptr){
	// Nothing here
}

SceneManager* SceneManager::getInstance() {
	if(_instance == nullptr){
		_instance = new SceneManager();
	}
	return _instance;
}

CScene* SceneManager::createScene(int sceneID) {
	// switch (sceneID){
	// case EScene::SPLASH_SCENE:
	// 	//Code here;
	// case EScene::MAIN_MENU_SCENE:
	// 	//Code here;
	// case EScene::GAME_OVER_SCENE:
	// 	//Code here;
	// case EScene::HELLO_WORLD_SCENE:
	// 	return HelloWorld::createScene();
//	}
	return nullptr;
}

CScene* SceneManager::createStartScene() {
	return createScene(EScene::HELLO_WORLD_SCENE);
}

CScene* SceneManager::getCurrentScene() {
	return dynamic_cast<CScene*>(Director::getInstance()->getRunningScene());
}

void SceneManager::replaceScene(int newSceneID){
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_SCENE_DURATION, createScene(newSceneID)));
}

void SceneManager::pushScene(int newSceneID){
	Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_SCENE_DURATION,createScene(newSceneID)));
}

void SceneManager::popLastScene(){
	Director::getInstance()->popScene();
}

void SceneManager::increaseScore(){
	//TODO Code here
}

void SceneManager::reset(){
	_score = 0;
	_scoreLabel->setString(std::to_string(_score));
}
