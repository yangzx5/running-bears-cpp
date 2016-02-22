#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include "Prey.h"

class Animal :public Prey
{
public:
	static Animal* createWithSpriteFrameName(const std::string& spriteFrameName);
};

#endif // !__ANIMAL_H__
