#ifndef __BATTLEFIELD_SCENE_H__
#define __BATTLEFIELD_SCENE_H__

#include "cocos2d.h"
#include "BigTwo.h"
#include "BigOne.h"
#include "SmallOne.h"
#include "SmallTwo.h"
#include "bullet.h"

class BattleField : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	
	void onTouchEnded(cocos2d::Touch* ptouches, cocos2d::Event*event)override;
	void myDefine(cocos2d::Node* who);
	bool onTouchBegan(cocos2d::Touch* pTouches, cocos2d::Event* pEvent);
	void collisionDetection();
	virtual void update(float delta);
	void action(cocos2d::Vec2 locInView);
	// implement the "static create()" method manually
	CREATE_FUNC(BattleField);

protected:
	cocos2d::Vec2 _beginPos;
	Bullet* bullet;
	void addPreys();
	void clearPreys();
	void route(Prey* prey);
	void adjustZorder();
	cocos2d::Vector<Prey*> preys;
	cocos2d::Vector<Bullet*> bullets;
	unsigned int _count;// _count records the frames elapsed
	cocos2d::Size _visibleSize;
	cocos2d::Vec2 _origin;
};

#endif // !__BATTLEFIELD_SCENE_H__

