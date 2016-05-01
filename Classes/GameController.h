#pragma once
#include <iostream>
#include <cocos2d.h>
#include <Edge.h>
#include <Block.h>
#include <Hero.h>
USING_NS_CC;

class GameController : public Ref{
private:
	Layer *_layer;
	float _positionY;
	Size visibleSize;
	int currentFrameIndex;
	int nextFrameCount;
	Edge *edge;
	Hero *hero;

private:
	void resetFrames();
	void addBlock();

public:
	virtual bool init(Layer *layer, float positionY);
	void onUpdate(float dt);
	bool hitTestPoint(Vec2 point);
	void onUserTouch();
	static GameController* create(Layer *layer, float positionY);
};