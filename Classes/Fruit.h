#ifndef __FRUIT_H__
#define __FRUIT_H__

#include "Prey.h"

class Fruit :public Prey
{
public:
	static Fruit* createWithSpriteFrameName(const std::string& spriteFrameName);
	void setResidenceTime(unsigned int residenceTime);
	unsigned int getResidenceTime();
protected:
	unsigned int _residenceTime;
};

#endif // !__FRUIT_H__

