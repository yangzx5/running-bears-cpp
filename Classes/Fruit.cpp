#include "Fruit.h"

USING_NS_CC;

Fruit * Fruit::createWithSpriteFrameName(const std::string & spriteFrameName)
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
	CCASSERT(frame != nullptr, msg);
#endif
	Fruit *sprite = new (std::nothrow) Fruit();
	if (sprite && frame && sprite->initWithSpriteFrame(frame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Fruit::setResidenceTime(unsigned int residenceTime)
{
	_residenceTime = residenceTime;
}

unsigned int Fruit::getResidenceTime()
{
	return _residenceTime;
}
