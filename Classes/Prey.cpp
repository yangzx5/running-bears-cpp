#include "Prey.h"

USING_NS_CC;

Prey* Prey::createWithSpriteFrameName(const std::string& spriteFrameName)
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
	CCASSERT(frame != nullptr, msg);
#endif
	Prey *sprite = new (std::nothrow) Prey();
	if (sprite && frame && sprite->initWithSpriteFrame(frame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Prey::initWithData(float x, float y, float scale)
{
	this->setPosition(x, y);
	this->setScale(scale);
}

void Prey::setAlive(bool isAlive)
{
	_isAlive = isAlive;
}

bool Prey::isAlive()
{
	return _isAlive;
}

void Prey::setMovingSpeed(float movingSpeed)
{
	_movingSpeed = movingSpeed;
}

float Prey::getMovingSpeed()
{
	return _movingSpeed;
}

void Prey::setScore(unsigned int score)
{
	_score = score;
}

unsigned int Prey::getScore()
{
	return _score;
}

void Prey::setHp(float hp)
{
	_hp = hp;
}

float Prey::getHp()
{
	return _hp;
}

void Prey::setCaptureProbability(float captureProbability)
{
	_captureProbability = captureProbability;
}

float Prey::getCaptureProbability()
{
	return _captureProbability;
}
