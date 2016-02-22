#ifndef __PREY_H__
#define __PREY_H__

#include "cocos2d.h"
#include "SystemConstant.h"

class Prey :public cocos2d::Sprite
{
public:
	static Prey* createWithSpriteFrameName(const std::string& spriteFrameName);
	virtual void initWithData(float x, float y, float scale);
	void setAlive(bool isAlive);
	bool isAlive();
	void setMovingSpeed(float movingSpeed);
	float getMovingSpeed();
	void setScore(unsigned int score);
	unsigned int getScore();
	void setHp(float hp);
	float getHp();
	void setCaptureProbability(float captureProbability);
	float getCaptureProbability();
protected:
	bool _isAlive;
	float _movingSpeed;
	unsigned int _score;
	float _hp;
	float _captureProbability;
};

#endif // !__PREY_H__
