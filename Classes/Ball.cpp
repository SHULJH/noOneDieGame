#include <Ball.h>

bool Ball::init() {
	Sprite::initWithFile("CloseSelected.png");

	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	setPhysicsBody(PhysicsBody::createBox(getContentSize()));
	setPosition(visibleSize.width / 2, visibleSize.height / 2);

	return true;
}