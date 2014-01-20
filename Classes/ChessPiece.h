#ifndef _CHESSPIECE_H_
#define _CHESSPIECE_H_

#include "cocos2d.h"
#include "define.h"
USING_NS_CC;

class ChessPiece : public CCSprite
{
public:
	ChessPiece * createWhitePiece();
	ChessPiece * createBlackPiece();
	void changeRole(enum PieceStatus role);
	void animationInit();
	CREATE_FUNC(ChessPiece);
private:
	int m_pieceRole;	
	CCSpriteFrameCache *m_frameCache;
	CCAnimate* m_WhiteToBlack;
	CCAnimate* m_BlackToWhite;
	ChessPiece* m_piece;
};

#endif
