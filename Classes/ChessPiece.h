#ifndef _CHESSPIECE_H_
#define _CHESSPIECE_H_

#include "cocos2d.h"

USING_NS_CC;

class ChessPiece : public CCSprite
{
public:
	ChessPiece * createWhitePiece();
	ChessPiece * createBlackPiece();
	void changeRole(enum Role role);
	void animationInit();
private:
	int m_pieceRole;	
	CCSpriteFrameCache *m_frameCache;
	CCAnimate* m_WhiteToBlack;
	CCAnimate* m_BlackToWhite;
	CCSprite * m_piece;
};

#endif
