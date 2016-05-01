#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255,255,255,255)) )
    {
        return false;
    }
    
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//gcs.pushBack(GameController::create(this, 30));
	//gcs.pushBack(GameController::create(this, 180));

	gcs.insert(0, GameController::create(this, 30));
	//gcs.insert(0, GameController::create(this, 250));

	scheduleUpdate();


	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact & contact) {
		this->unscheduleUpdate();

		Director::getInstance()->replaceScene(GameOver::createScene());

		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [this](Touch *t, Event *e) {
		for (auto it = gcs.begin(); it != gcs.end(); it++) {
			if ((*it)->hitTestPoint(t->getLocation())) {
				log("%f, %f", t->getLocation().x, t->getLocation().y);
				(*it)->onUserTouch();

				break;
			}
		}

		return false;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    //add edge
	//auto edge = Edge::create();
	//edge->setPosition(visibleSize.width/2, visibleSize.height/2);
	//addChild(edge);

	//auto hero = Hero::create();
	///*hero->setPhysicsBody(PhysicsBody::createBox(Size(44, 52)));*/
	//hero->setPosition(50, 50);
	//addChild(hero);

	//Size s = Size((rand() % 20) + 5, (rand() % 30) + 10);
	//auto block = Block::create();
	///*block->setTextureRect(Rect(0, 0, s.width, s.height));
	//block->setContentSize(s);
	//block->setPositionX(visibleSize.width);
	//block->scheduleUpdate();
	//block->setPhysicsBody(PhysicsBody::createBox(s));*/
	//addChild(block);
	//block->setPositionY(block->getContentSize().height/2);

	/*auto body = Sprite::create("CloseSelected.png");
	body->setPhysicsBody(PhysicsBody::createBox(body->getContentSize()));
	body->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(body);

	auto test = Ball::create();
	addChild(test);*/

    return true;
}

void HelloWorld::update(float dt) {
	for (auto it = gcs.begin(); it != gcs.end(); it++) {
		(*it)->onUpdate(dt);
	}
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
