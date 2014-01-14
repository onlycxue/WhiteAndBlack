#ifndef _STORELAYER_H_
#define _STORELAYER_H_

#include "cocos2d.h"

class StoreLayer : public cocos2d::CCLayer
{
public:
	virtual bool init();




};

class WhiteStoreLayer : public StoreLayer
{
public:
	virtual bool init();



};

class BlackStoreLayer: public StoreLayer
{
public:
	virtual bool init()



};
