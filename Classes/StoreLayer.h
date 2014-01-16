#ifndef _STORELAYER_H_
#define _STORELAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class StoreLayer : public cocos2d::CCLayer
{
public:
	virtual bool init();
	virtual void update(float dt);
	virtual void onExit();
	CC_SYNTHESIZE(CCSprite*,_Role,Role);
	CC_SYNTHESIZE(int,_store,Store);
	CC_SYNTHESIZE(int,_time,Time);

    CCLabelTTF* m_store;
	CCLabelTTF* m_time;
	
	virtual void updateStore();
	virtual void updateTime();
	CREATE_FUNC(StoreLayer);

};

class WhiteStoreLayer : public StoreLayer
{
public:
	virtual bool init();
	CREATE_FUNC(WhiteStoreLayer);	
};

class BlackStoreLayer: public StoreLayer
{
public:
	virtual bool init();

	CREATE_FUNC(BlackStoreLayer);
};

#endif
