#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_


#include "cocos2d.h"
#include "SelectWindow.h"
//#include "ChessBoardLayer.h"
#include "AIChessBoard.h"
#include "VSChessBoard.h"
#include "StoreLayer.h"
#include "define.h"
#include "../../../CocosDenshion/include/SimpleAudioEngine.h"

class GameScene : public cocos2d::CCLayer
{

public:
	enum GameMode{
		SingalMode,
		MoreMode
	};
	virtual bool init();
	static cocos2d::CCScene* scene(GameMode mode);
	void menuBackCallback(CCObject* pSender);
	CREATE_FUNC(GameScene);
private:
    static	cocos2d::CCScene* m_parentScene;
};


#endif
