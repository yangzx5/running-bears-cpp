#include "cocos2d.h"
#include "SystemConstant.h"
class Bullet : public cocos2d::Sprite
{
public:
	virtual void initWithData(float x, float y, float scale);
	//virtual void run() = 0;
	static Bullet* createWithSpriteFrameName(const std::string& spriteFrameName);
	static Bullet* create(const std::string& filename);
	void setbulletspeed(float Bulletspeed);
	float getbulletspeed();
	void setScore(unsigned int score);
	unsigned int getScore();
	void setpower(float power);
	float getpower();
protected:
	int _power;//威力
	float _Bulletspeed;//子弹速度
	unsigned int _score;//积分
	};