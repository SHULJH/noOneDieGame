#include <Block.h>


bool Block::init() {
	Sprite::init();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size s = Size(rand() % 20 + 20, rand() % 30 + 20);	
	setTextureRect(Rect(0, 0, s.width, s.height));
	setContentSize(s);
	setColor(Color3B(0,0,0));
	setPositionX(visibleSize.width);
	scheduleUpdate();
	setPhysicsBody(PhysicsBody::createBox(s));

	getPhysicsBody()->setDynamic(false);
	getPhysicsBody()->setContactTestBitmask(1);

	return true;
}

void Block::update(float dt) {
	this->setPositionX(getPositionX() - 4);

	if (getPositionX() < 0) {
		unscheduleUpdate();
		removeFromParent();
	}
}