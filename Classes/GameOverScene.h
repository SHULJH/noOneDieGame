#pragma once
#include <cocos2d.h>
USING_NS_CC;

class GameOver : public LayerColor {
private:
	Size visibleSize;

public:
	virtual bool init();
	CREATE_FUNC(GameOver);

	static Scene* createScene();
};