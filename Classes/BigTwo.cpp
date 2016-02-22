#include "BigTwo.h"

USING_NS_CC;

BigTwo * BigTwo::createWithSpriteFrameName(const std::string & spriteFrameName)
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
	CCASSERT(frame != nullptr, msg);
#endif
	BigTwo *sprite = new (std::nothrow) BigTwo();
	if (sprite && frame && sprite->initWithSpriteFrame(frame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void BigTwo::initWithData(float x, float y, float scale)
{
	Prey::initWithData(x, y, scale);
	this->setTag(BIG_TWO_TAG);
	this->setMovingSpeed(DEFAULT_QUIET_SPEED);
	this->setScore(BIG_TWO_SCORE);
	this->setHp(BIG_TWO_HP);
	this->setCaptureProbability(BIG_TWO_CAPTURE_PROBABILITY);
}

void BigTwo::runTo(const Vec2 & endPosition)
{
	auto animation = AnimationCache::getInstance()->getAnimation(BIG_TWO_ANIMATION_NAME);
	if (animation)
	{
		animation->setDelayPerUnit(BIG_TWO_STRIDE / _movingSpeed / BIG_TWO_FRAMES);
		auto animate = Animate::create(animation);
		auto repeatAnimate = RepeatForever::create(animate);
		auto distance = endPosition.distance(this->getPosition());
		auto moveTo = MoveTo::create(distance / _movingSpeed, endPosition);
		this->runAction(repeatAnimate);
		this->runAction(moveTo);
	}
}
