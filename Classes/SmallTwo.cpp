#include "SmallTwo.h"

USING_NS_CC;

SmallTwo * SmallTwo::createWithSpriteFrameName(const std::string & spriteFrameName)
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
	CCASSERT(frame != nullptr, msg);
#endif
	SmallTwo *sprite = new (std::nothrow) SmallTwo();
	if (sprite && frame && sprite->initWithSpriteFrame(frame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void SmallTwo::initWithData(float x, float y, float scale)
{
	Animal::initWithData(x, y, scale*0.8);
	this->setTag(SMALL_TWO_TAG);
	this->setMovingSpeed(SMALL_TWO_SPEED);
	this->setScore(SMALL_TWO_SCORE);
	this->setHp(SMALL_TWO_HP);
	this->setCaptureProbability(SMALL_TWO_CAPTURE_PROBABILITY);
}

void SmallTwo::run()
{
	auto animation = AnimationCache::getInstance()->getAnimation(RES_ANIMATION_BEAR_TWO);
	if (animation)
	{
		animation->setDelayPerUnit(SMALL_TWO_STRIDE / _movingSpeed / BEAR_TWO_FRAMES);
		auto animate = Animate::create(animation);
		auto repeatAnimate = RepeatForever::create(animate);
		this->runAction(repeatAnimate);
	}
}
