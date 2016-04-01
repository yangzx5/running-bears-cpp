#include "BigOne.h"

USING_NS_CC;

BigOne * BigOne::createWithSpriteFrameName(const std::string & spriteFrameName)
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
	CCASSERT(frame != nullptr, msg);
#endif
	BigOne *sprite = new (std::nothrow) BigOne();
	if (sprite && frame && sprite->initWithSpriteFrame(frame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void BigOne::initWithData(float x, float y, float scale)
{
	Animal::initWithData(x, y, scale);
	this->setTag(BIG_ONE_TAG);
	this->setMovingSpeed(BIG_ONE_SPEED);
	this->setScore(BIG_ONE_SCORE);
	this->setHp(BIG_ONE_HP);
	this->setCaptureProbability(BIG_ONE_CAPTURE_PROBABILITY);
}

void BigOne::run()
{
	auto animation = AnimationCache::getInstance()->getAnimation(RES_ANIMATION_BEAR_ONE);
	if (animation)
	{
		animation->setDelayPerUnit(BIG_ONE_STRIDE / _movingSpeed / BEAR_ONE_FRAMES);
		auto animate = Animate::create(animation);
		auto repeatAnimate = RepeatForever::create(animate);
		this->runAction(repeatAnimate);
	}
}


