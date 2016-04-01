#include "SmallOne.h"

USING_NS_CC;

SmallOne * SmallOne::createWithSpriteFrameName(const std::string & spriteFrameName)
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
	CCASSERT(frame != nullptr, msg);
#endif
	SmallOne *sprite = new (std::nothrow) SmallOne();
	if (sprite && frame && sprite->initWithSpriteFrame(frame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void SmallOne::initWithData(float x, float y, float scale)
{
	Animal::initWithData(x, y, scale*0.8f);
	this->setTag(SMALL_ONE_TAG);
	this->setMovingSpeed(SMALL_ONE_SPEED);
	this->setScore(SMALL_ONE_SCORE);
	this->setHp(SMALL_ONE_HP);
	this->setCaptureProbability(SMALL_ONE_CAPTURE_PROBABILITY);
}

void SmallOne::run()
{
	auto animation = AnimationCache::getInstance()->getAnimation(RES_ANIMATION_BEAR_ONE);
	if (animation)
	{
		animation->setDelayPerUnit(SMALL_ONE_STRIDE / _movingSpeed / BEAR_ONE_FRAMES);
		auto animate = Animate::create(animation);
		auto repeatAnimate = RepeatForever::create(animate);
		this->runAction(repeatAnimate);
	}
}
