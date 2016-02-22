#include "BattleFieldScene.h"

USING_NS_CC;

Scene* BattleField::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = BattleField::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool BattleField::init()
{
	// super init first
	if (!Layer::init())
	{
		return false;
	}

	// set time to zero
	_count = 0;

	// calculate visible size and origin
	_visibleSize = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();

	// add sprite frames and animations into cache
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/bear2.plist");
	AnimationCache::getInstance()->addAnimationsWithFile("res/animations.plist");

	// add background picture
	auto bgSprite = Sprite::create("background.png");
	if (bgSprite)
	{
		// position the sprite on the center of the screen
		bgSprite->setPosition(Vec2(_visibleSize.width / 2 + _origin.x, _visibleSize.height / 2 + _origin.y));
		bgSprite->setTag(NONPREY_TAG);

		// add the sprite as a child to this layer
		this->addChild(bgSprite, 0);
	}
	scheduleUpdate();

	return true;
}

void BattleField::update(float delta)
{
	_count++;
	bool flag = false;
	BigTwo* bear2;
	if (_count % 200 == 0)
	{
		// add bear2
		bear2 = BigTwo::createWithSpriteFrameName("_0000_1.png");// res/bear2.plist
		if (bear2)
		{
			bear2->initWithData(_origin.x + _visibleSize.width + bear2->getContentSize().width / 2, _visibleSize.height / 2 + _origin.y, 1);
			flag = true;
		}
		
		/*
		auto bear2Sprite2 = BigTwo::createWithSpriteFrameName("_0000_1.png");// res/bear2.plist
		if (bear2Sprite2)
		{
			bear2Sprite2->initWithData(_origin.x - bear2Sprite->getContentSize().width / 2, _visibleSize.height / 2 + _origin.y, 1);
			bear2Sprite2->setFlippedX(true);
			this->addChild(bear2Sprite2);
			bear2Sprite2->runTo(Vec2(_origin.x + _visibleSize.width + (bear2Sprite->getContentSize().width / 2), _visibleSize.height / 2 + _origin.y));
		}
		*/
	}
	if (flag)
	{
		bear2->runTo(Vec2(_origin.x - (bear2->getContentSize().width / 2), _visibleSize.height / 2 + _origin.y));
		this->addChild(bear2);
	}
}
