#include "BattleFieldScene.h"
#include<cmath>


//#define bulletspeed 1920/200*60
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
	//触摸事件
	this->setTouchEnabled(true);
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(BattleField::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(BattleField::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}
bool BattleField::onTouchBegan(Touch* pTouches, Event* pEvent)
{

	return true;
}
//触摸响应函数
void BattleField::onTouchEnded(Touch* pTouches, Event*pEvent)
{
	auto locInView = pTouches->getLocation();
	double dis, angle, sum;
	double xaxis = locInView.x - 960;
	double yaxis = locInView.y - 20;
	dis = sqrt(pow(xaxis, 2) + pow(yaxis, 2));
	angle = (atan(yaxis / xaxis)) / 3.14 * 180;
	CCSize screenSize = CCDirector::sharedDirector()->getVisibleSize();
	bullet = Bullet::create("bullet.png");
	bullet->setbulletspeed(1920*60 / 192);
	auto bulletspeed = bullet->getbulletspeed();
	bullet->setPosition(ccp(960, 20));
	if (locInView.x >= 960)
		bullet->setRotation(180 - angle);
	else
		bullet->setRotation(-angle);
	bullets.pushBack(bullet);
	this->addChild(bullet);
	CCMoveTo* move = CCMoveTo::create(dis / bulletspeed, ccp(locInView.x, locInView.y));
	CCLOG("Decimals: %lf %lf %lf %lf %lf\n", angle, dis, xaxis, yaxis, atan(-yaxis / xaxis));

	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(BattleField::myDefine));
	CCSequence* actions = CCSequence::create(move, disappear, NULL);
	bullet->runAction(actions);
	//bullet = CCSprite::create("bullet.png");
	//bullet->setPosition(ccp(960, 20));

}
//碰撞检测函数
void BattleField::CollisionDetection()
{
	
	
	if (bullets.empty() || preys.empty()) {
		return;
	}
	// 1 
	Vector<Prey*> preyNeedToDelete;
	Vector<Bullet*> bulletNeedToDelete;
	// 2
	for (int i = 0; i < bullets.size(); i++)
	{
		auto  bullet1 = bullets.at(i);
		/*auto  bulletRect = Rect(bullet->getPositionX() + bullet->getParent()->getPositionX() - bullet->getContentSize().width / 2,
			bullet->getPositionY() + bullet->getParent()->getPositionY() - bullet->getContentSize().height / 2,
			bullet->getContentSize().width,
			bullet->getContentSize().height);*/
		auto bulletRect = bullet1->getBoundingBox();

		
		for (int j = 0; j < preys.size(); j++)
		{
			auto enemy = preys.at(j);
			auto enemyRect = enemy->getBoundingBox();
			// 4
			if (bulletRect.intersectsRect(enemyRect))// 碰撞成功
			{
				bullet->setpower(2);
				auto power = bullet->getpower();
				auto hp = enemy->getHp();
				hp = hp - 2;
				enemy->setHp(hp);//扣血
				bulletNeedToDelete.pushBack(bullet1);
				if(hp<=0)
				preyNeedToDelete.pushBack(enemy);
				
				// 5
				break;
			}
		}
		// 移除死了的prey
		for (Prey* preytemp:preyNeedToDelete)
		{
			
			preys.eraseObject(preytemp);
			preytemp->removeFromParentAndCleanup(true);
		}
		preyNeedToDelete.clear();
	}
	// 移除死了的bullet
	for (const auto& bulletTemp : bulletNeedToDelete)
	{
		bullets.eraseObject(bulletTemp);
		//bulletTemp->removeFromParent();
		bulletTemp->removeFromParentAndCleanup(true);
	}
	bulletNeedToDelete.clear();
}

void BattleField::myDefine(CCNode* who)
{
	who->removeFromParentAndCleanup(true);
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
	CollisionDetection();
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
