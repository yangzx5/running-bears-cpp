#include "HelloWorldScene.h"
#include "2d\CCLabelTTF.h"
#include "math.h"
#include "cstdio"
#include "iostream"
#define bulletspeed 1280/200*60



USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
   
	//菜单事件
	/*CCMenuItemImage* item = CCMenuItemImage::create("button2.png",
		"button2.png",
		"button2.png",
		this,
		menu_selector(HelloWorld::responseFunc));


	item->setPosition(ccp(1000, 400));
	

	CCMenu* menu = CCMenu::create(item, NULL);
	this->addChild(menu);*/
	
	
	/*/创建精灵-子弹
	CCSize screenSize = CCDirector::sharedDirector()->getVisibleSize();
	bullet = CCSprite::create("bullet.png");
	bullet->setPosition(ccp(640, 100));
	this->addChild(bullet);
	/*CCLabelTTF* ttf0 = CCLabelTTF::create("111111", "Helvetian", 12, CCSizeMake(256, 32), TextHAlignment::LEFT, TextVAlignment::TOP);
	ttf0->setAnchorPoint(ccp(200, 200));
	this->addChild(ttf0);*/
	

	
	this->setTouchEnabled(true);
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}
void HelloWorld::responseFunc(CCObject* obj)
{
	CCMoveTo* move = CCMoveTo::create(2, ccp(100, 360));
	//CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	//CCSequence* actions = CCSequence::create(move, disappear, NULL);
	bullet->runAction(move);
}

bool HelloWorld::onTouchBegan(Touch* pTouches, Event* pEvent)
{
	/*CCMoveTo* move = CCMoveTo::create(2, ccp(100, 360));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	CCSequence* actions = CCSequence::create(move, disappear, NULL);
	bullet->runAction(move);*/
	
	return true;
	
	
}
void HelloWorld::onTouchEnded(CCTouch* pTouches, CCEvent*pEvent)
{
	auto locInView = pTouches->getLocation();
	//CCPoint loc = CCDirector::sharedDirector()->convertToGL(locInView); 
	//CCLabelTTF* pLabel = CCLabelTTF::create("loc.x", "Aral", 30);//要显示的内容，字体，字号  
	//这里也可以使用下面方法改变要显示的内容  
	//pLabel->setPosition(ccp(100, 100));
	//this->addChild(pLabel, 1);
	double dis, angle, sum;
	double xaxis = locInView.x - 640;
	double yaxis = locInView.y - 20;
	dis = sqrt(pow(xaxis, 2) + pow(yaxis, 2));
	angle = (atan(yaxis / xaxis)) / 3.14 * 180;
	CCSize screenSize = CCDirector::sharedDirector()->getVisibleSize();
	bullet = CCSprite::create("bullet.png");
	bullet->setPosition(ccp(640, 20));
	if(locInView.x>=640)
	bullet->setRotation(180-angle);
	else
	bullet->setRotation(-angle);
	this->addChild(bullet);
	CCMoveTo* move = CCMoveTo::create(dis / bulletspeed, ccp(locInView.x, locInView.y));
	CCLOG("Decimals: %lf %lf %lf %lf %lf\n", angle, dis,xaxis,yaxis, atan(-yaxis / xaxis));

	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	CCSequence* actions = CCSequence::create(move, disappear, NULL);
	bullet->runAction(actions);
	bullet = CCSprite::create("bullet.png");
	bullet->setPosition(ccp(640, 20));
}
void HelloWorld::myDefine(CCNode* who)
{
	who->removeFromParentAndCleanup(true);
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
