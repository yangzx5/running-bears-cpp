#ifndef __SMALLTWO_H__
#define __SMALLTWO_H__

#include "Animal.h"

class SmallTwo :public Animal
{
public:
	static SmallTwo* createWithSpriteFrameName(const std::string& spriteFrameName);
	virtual void initWithData(float x, float y, float scale);
	virtual void run();
};

#endif // !__SMALLTWO_H__
