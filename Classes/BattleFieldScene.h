#ifndef __BATTLEFIELD_SCENE_H__
#define __BATTLEFIELD_SCENE_H__

#include "cocos2d.h"

class BattleField : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(BattleField);
};

#endif // !__BATTLEFIELD_SCENE_H__

