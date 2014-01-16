#ifndef _CHESSBOARDLAYER_
#define _CHESSBOARDLAYER_

#include "cocos2d.h"
#include "StoreLayer.h" 

USING_NS_CC;

class ChessBoardLayer : public cocos2d::CCLayer
{
public:
	virtual bool init();
	virtual void ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent);
//	virtual void ccTouches
	CREATE_FUNC(ChessBoardLayer);	
private:
	WhiteStoreLayer* m_whiteStatus;
	BlackStoreLayer* m_blackStatus;

};

#endif
