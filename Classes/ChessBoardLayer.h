#ifndef _CHESSBOARDLAYER_
#define _CHESSBOARDLAYER_

#include "cocos2d.h"
#include "StoreLayer.h" 
#include "define.h"
#include "ChessPiece.h"
#include <iostream>
#include <map>

USING_NS_CC;
//chess board position
typedef struct 
{
	int x;
	int y;
}ChessCoordinate;

class ChessBoardLayer : public cocos2d::CCLayer
{
public:

	virtual bool init();
	virtual void ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent);
	virtual void update(float dt);
	void createPiece(int x,int y,enum PieceStatus role);
	ChessCoordinate pixelToChessCoordinate(CCPoint point);
	void chessBufInit();
	std::string makeKey(int x,int y);
	//
	int judgeRule(int x,int y,void *chess,enum PieceStatus currentRole);
	void DicAddChild(int x,int y,ChessPiece *piece);	
	ChessPiece* getPieceFromDic(int x,int y);
	void setCurrentRole(PieceStatus role);	
	void changeCurrentRole();

	void drawChessPiece();

	CREATE_FUNC(ChessBoardLayer);	
private:
	WhiteStoreLayer* m_whiteStatus;
	BlackStoreLayer* m_blackStatus;
	int m_whiteStore;
	int m_blackStore;
	int chessBuf[8][8];
	static int dir[8][2];
	enum PieceStatus m_currentRole;	
//	CCDictionary *m_chessPieceDic;
	ChessPiece* m_chessPiece;

	typedef std::map<std::string,ChessPiece*> ChessPieceDic;

	ChessPieceDic m_chessPieceDic;
};

#endif
