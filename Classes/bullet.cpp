#include "bullet.h"

USING_NS_CC;

void Bullet::initWithData(float x, float y, float scale)
{
	this->setPosition(x, y);
	this->setScale(scale);
}

/*Bullet * Bullet::createWithSpriteFrameName(const std::string & spriteFrameName)
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
	CCASSERT(frame != nullptr, msg);
#endif
	Bullet *sprite = new (std::nothrow) Bullet();
	if (sprite && frame && sprite->initWithSpriteFrame(frame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}*/

Bullet* Bullet::create(const std::string& filename)
{
	Bullet *sprite = new (std::nothrow) Bullet();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}


void Bullet::setbulletspeed(float Bulletspeed)
{
	_Bulletspeed = Bulletspeed;
}

float Bullet::getbulletspeed()
{
	return _Bulletspeed;
}

void Bullet::setScore(unsigned int score)
{
	_score = score;
}

unsigned int Bullet::getScore()
{
	return _score;
}

void Bullet::setpower(float power)
{
	_power = power;
}

float Bullet::getpower()
{
	return _power;
}


