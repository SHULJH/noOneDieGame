#include <GameOverScene.h>

bool GameOver::init() {
	LayerColor::initWithColor(Color4B::WHITE);

	visibleSize = Director::getInstance()->getVisibleSize();

	auto label = Label::create();
	label->setString("Gane Over");
	label->setSystemFontSize(40);
	label->setColor(Color3B::BLACK);
	addChild(label);
	label->setPosition(visibleSize.width/2, visibleSize.height/2);

	return true;
}

cocos2d::Scene* GameOver::createScene() {
	auto s = cocos2d::Scene::create();

	auto l = GameOver::create();
	s->addChild(l);

	return s;
}