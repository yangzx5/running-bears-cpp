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
	int _power;//����
	float _Bulletspeed;//�ӵ��ٶ�
	unsigned int _score;//����
	};