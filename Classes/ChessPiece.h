#ifndef _CHESSPIECE_H_
#define _CHESSPIECE_H_

#include "cocos2d.h"
#include "define.h"
USING_NS_CC;

class ChessPiece : public CCSprite
{
public:
	virtual bool init();
	void changeRole(enum PieceStatus role);
	void animationInit();
protected:
	int m_pieceRole;	
	CCSpriteFrameCache *m_frameCache;
	CCAnimate* m_WhiteToBlack;
	CCAnimate* m_BlackToWhite;
};

class WhiteChessPiece : public ChessPiece
{
public:
	virtual bool init();

	CREATE_FUNC(WhiteChessPiece);

};

class BlackChessPiece : public ChessPiece
{
public:
	virtual bool init();
	

	CREATE_FUNC(BlackChessPiece);

};

#endif
