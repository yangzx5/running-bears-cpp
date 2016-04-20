#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "deprecated\CCDeprecated.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
	cocos2d::Sprite* bullet;
	cocos2d::LabelTTF* pLabel;
    virtual bool init();
    
	void onTouchEnded(cocos2d::CCTouch* ptouches,cocos2d::CCEvent*event);
	void myDefine(cocos2d::CCNode* who);
	// a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void responseFunc(cocos2d::CCObject* obj);
	
	
	
	bool onTouchBegan(cocos2d::Touch* pTouches,cocos2d::Event* pEvent);
	
	// 触摸事件响应函数;
	// implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
