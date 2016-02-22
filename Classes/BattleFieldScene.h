#ifndef __BATTLEFIELD_SCENE_H__
#define __BATTLEFIELD_SCENE_H__

#include "cocos2d.h"
#include "BigTwo.h"

class BattleField : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void update(float delta);

	// implement the "static create()" method manually
	CREATE_FUNC(BattleField);

protected:
	unsigned int _count;// _count records the frames elapsed
	cocos2d::Size _visibleSize;
	cocos2d::Vec2 _origin;
};

#endif // !__BATTLEFIELD_SCENE_H__

