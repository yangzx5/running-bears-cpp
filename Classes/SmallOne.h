#ifndef __SMALLONE_H__
#define __SMALLONE_H__

#include "Animal.h"

class SmallOne :public Animal
{
public:
	static SmallOne* createWithSpriteFrameName(const std::string& spriteFrameName);
	virtual void initWithData(float x, float y, float scale);
	virtual void run();
};

#endif // !__SMALLONE_H__
