#include "BattleFieldScene.h"
#include<cmath>

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
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(RES_TEXTURE);
	AnimationCache::getInstance()->addAnimationsWithFile(RES_ANIMATION);

	// add background picture
	auto bgSprite = Sprite::create(RES_BACKGROUND);
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
	if (_count % 200 == 0)
	{
		addPreys();
	}	
	adjustZorder();
	clearPreys();
}

// 按规定的数量每单位时间添加猎物
void BattleField::addPreys()
{
	Prey* prey = nullptr;
	for (auto i = 0; i < EMERGENCE_NUMBER_PER_UNIT_TIME_QUIET_BEAR; i++)
	{
		auto random = rand() % 4;
		switch (random)
		{
		case 0:
			prey = BigOne::createWithSpriteFrameName(RES_BEAR_ONE);
			break;
		case 1:
			prey = BigTwo::createWithSpriteFrameName(RES_BEAR_TWO);
			break;
		case 2:
			prey = SmallOne::createWithSpriteFrameName(RES_BEAR_ONE);
			break;
		case 3:
			prey = SmallTwo::createWithSpriteFrameName(RES_BEAR_TWO);
			break;
		}
		if (prey)
		{
			route(prey);
			this->addChild(prey);
			prey->setAlive(true);
			preys.pushBack(prey);
		}
	}
}

// clear the preys that is not at the screen
void BattleField::clearPreys()
{
	for (auto itor = preys.begin(); itor != preys.end();)
	{
		if ((*itor)->getOpacity() == 0)
		{
			(*itor)->setAlive(false);
			this->removeChild(*itor, true);
			itor = preys.erase(itor);
		}
		else
		{
			itor++;
		}
	}

}

// adjust the Z-order of the sprites 
void BattleField::adjustZorder()
{
	for (auto itor = preys.begin(); itor != preys.end(); itor++)
	{
		if ((*itor)->getOpacity() != 0)
		{
			for (auto itor2 = itor + 1; itor2 != preys.end(); itor2++)
			{
				if ((*itor2)->getOpacity() != 0)
				{
					if ((*itor)->getBoundingBox().intersectsRect((*itor2)->getBoundingBox()))
					{
						if ((*itor)->getPositionY() > (*itor2)->getPositionY())
						{
							(*itor)->setLocalZOrder(1);
							(*itor2)->setLocalZOrder(2);
						}
						else
						{
							(*itor2)->setLocalZOrder(1);
							(*itor)->setLocalZOrder(2);
						}
					}
				}
			}
		}
	}
}

// produce a list of cordinates for the running route of an animal 
void BattleField::route(Prey* prey)
{
	std::list<Vec2> cordinates;
	auto runningAreaY1 = _origin.y + UI_AREA_HEIGHT;
	auto runningAreaY2 = DESIGN_RESOLUTION_HEIGHT - FOREST_AREA_HEIGHT;
	auto runningAreaX1 = _origin.x - prey->getContentSize().width/2;
	auto runningAreaX2 = _origin.x + _visibleSize.width + prey->getContentSize().width / 2;
	auto appearLength = unsigned int(runningAreaY2 - runningAreaY1);
	auto random = rand() % (appearLength * 2);
	float startY;
	auto distance = 0;
	if (random < appearLength)
	{
		startY = random + runningAreaY1;
		prey->initWithData(runningAreaX1, startY, 1);
		auto cordinate = Vec2(runningAreaX1, startY);
		cordinates.push_back(cordinate);
		do
		{
			auto randomX = rand() % int(_visibleSize.width / 8) + _visibleSize.width / 5;
			cordinate.x += randomX;
			auto randomY = rand() % int(randomX/1.5) - randomX / 3;
			cordinate.y += randomY;
			if (cordinate.y < runningAreaY1)
			{
				cordinate.y = runningAreaY1;
			}
			if (cordinate.y > runningAreaY2 )
			{
				cordinate.y = runningAreaY2;
				cordinates.push_back(cordinate);
				distance = distance + sqrt(randomY*randomY + randomX*randomX);
				break;
			}
			cordinates.push_back(cordinate);
			distance = distance + sqrt(randomY*randomY + randomX*randomX);
		} while (cordinate.x <= runningAreaX2&&cordinate.x >= runningAreaX1&& cordinate.y <= runningAreaY2&& cordinate.y >= runningAreaY1);
	}
	else
	{
		startY = random - appearLength + runningAreaY1;
		prey->initWithData(runningAreaX2, startY, 1);
		prey->setFlippedX(true);
		auto cordinate = Vec2(runningAreaX2, startY);
		cordinates.push_back(cordinate);
		do
		{
			auto randomX = rand() % int(_visibleSize.width / 8) + _visibleSize.width / 5;
			cordinate.x -= randomX;
			auto randomY = rand() % int(randomX/1.5) - randomX / 3;
			cordinate.y += randomY;
			if (cordinate.y < runningAreaY1)
			{
				cordinate.y = runningAreaY1;
			}
			else if (cordinate.y > runningAreaY2)
			{
				cordinate.y = runningAreaY2;
				cordinates.push_back(cordinate);
				distance = distance + sqrt(randomY*randomY + randomX*randomX);
				break;
			}
			cordinates.push_back(cordinate);
			distance = distance + sqrt(randomY*randomY + randomX*randomX);
		} while (cordinate.x <= runningAreaX2&&cordinate.x >= runningAreaX1&& cordinate.y <= runningAreaY2&& cordinate.y >= runningAreaY1);
	}
	PointArray* controlPoints = PointArray::create(cordinates.size());
	for (auto itor = cordinates.begin(); itor != cordinates.end(); itor++)
	{
		controlPoints->addControlPoint(*itor);
	}
	prey->run();
	ActionInterval* bosslineTo = CardinalSplineTo::create(distance / prey->getMovingSpeed(), controlPoints, 0);
	ActionInterval* fadeout = FadeOut::create(1.5f);
	Action* action = Sequence::create(bosslineTo, fadeout,NULL);
	prey->runAction(action);

}
