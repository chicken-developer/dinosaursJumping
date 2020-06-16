#include "CObject.h"
USING_NS_CC;

CObject::CObject():_isAlive(true){
	
}

bool CObject::init(){
	if(!Node::init()){
		return false;
	}

	return true;
}

void CObject::updateObject(float deltaTime){
	run(deltaTime);
}

void CObject::run(float deltaTime) {}

cocos2d::Rect CObject::getRect(){
	auto posA = this->getPosition();
	auto sizeA = this->getContentSize();

	return Rect(posA.x - sizeA.width / 2.0f, posA.y - sizeA.height / 2.0f, sizeA.width, sizeA.height);
}

void CObject::createPhysicBody(bool isDynamic, bool isRotationEnable){
	auto material = PHYSICSBODY_MATERIAL_DEFAULT;
	auto offset = -1.0f * Vec2(this->getContentSize().width / 2.0f, this->getContentSize().height / 2.0f);
	auto physicBody = PhysicsBody::createBox(this->getContentSize(), material, offset);

	physicBody->setDynamic(isDynamic);
	physicBody->setRotationEnable(isRotationEnable);

	this->addComponent(physicBody);
}

void CObject::onCollisionPostExit(CObject* gameObject) {}



