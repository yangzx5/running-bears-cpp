#ifndef __BIG_ONE_H__
#define __BIG_ONE_H__

#include  "Animal.h"

class BigOne :public Animal
{
public:
	static BigOne* createWithSpriteFrameName(const std::string& spriteFrameName);
	virtual void initWithData(float x, float y, float scale);
	virtual void run();
};


#endif // !__BIG_ONE_H__
