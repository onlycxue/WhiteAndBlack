#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_


#include "cocos2d.h"
#include "SelectWindow.h"
#include "ChessBoardLayer.h"
#include "StoreLayer.h"


class GameScene : public cocos2d::CCLayer
{

public:
	virtual bool init();
	static cocos2d::CCScene* scene();
	void menuBackCallback(CCObject* pSender);
	CREATE_FUNC(GameScene);
private:
    static	cocos2d::CCScene* m_parentScene;
};


#endif
