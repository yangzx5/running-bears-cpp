#ifndef __BIGTWO_H__
#define __BIGTWO_H__

#include "Animal.h"

class BigTwo :public Animal
{
public:
	static BigTwo* createWithSpriteFrameName(const std::string& spriteFrameName);
	virtual void initWithData(float x, float y, float scale);
	virtual void run();
};

#endif // !__BIGTWO_H__

