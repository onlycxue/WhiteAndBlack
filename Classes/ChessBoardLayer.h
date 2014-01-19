#ifndef _CHESSBOARDLAYER_
#define _CHESSBOARDLAYER_

#include "cocos2d.h"
#include "StoreLayer.h" 

USING_NS_CC;

//chess board position
#define STARTPOINT ccp(320,680)
#define ENDPOINT ccp(960,40)
#define PIECESIZE CCSizeMake(80,80)
#define SCREENSIZE CCSizeMake(1280,720)
#define GRIDNUM 8

typedef struct 
{
	int x;
	int y;
}ChessCoordinate;

class ChessBoardLayer : public cocos2d::CCLayer
{
public:
	enum PieceStatus
	{
		EMPTY,
		BLACK,
		WHITE,
	};
	virtual bool init();
	virtual void ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent);
	virtual void update(float dt);
	void createPiece(CCPoint point,enum Role role);
	ChessCoordinate pixelToChessCoordinate(CCPoint point);
	void chessBufInit();
	void chessDirInit();
	//make key for chesspiece dictionary
	CCString makeKey(int x,int y);
//	virtual void ccTouches
	CREATE_FUNC(ChessBoardLayer);	
private:
	WhiteStoreLayer* m_whiteStatus;
	BlackStoreLayer* m_blackStatus;
	int m_whiteStore;
	int m_blackStore;
	int chessBuf[8][8];
	int dir[8][2];
	CCDictionary *m_chessPiecebuf;
};

#endif
