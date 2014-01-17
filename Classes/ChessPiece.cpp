/*
 * =====================================================================================
 *
 *       Filename:  ChessPiece.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/17/2014 04:04:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "ChessPiece.h"

ChessPiece* ChessPiece::createWhitePiece()
{
	animationInit();

	m_piece = CCSprite::create();
	CCSpriteFrame *frame = m_frameCache->spriteFrameByName("");	
	m_piece->setDisplayFrame(frame);
	m_pieceRole = WHITE;

	return WhitePiece;
}

ChessPiece* ChessPiece::createBlackPiece()
{
	animationInit();

	m_piece = CCSprite::create();
	CCSpriteFrame *frame = m_frameCache->spriteFrameByName("");	
	m_piece->setDisplayFrame(frame);
	m_pieceRole = BLACK;

	return BlackPiece;

}

void ChessPiece::animationInit()
{
	m_frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	m_frameCache->addSpriteFramesWithFile("");
	
	CCAnimationCache::purgeSharedAnimationCache();
	CCAnimationCache *animCache = CCAnimationCache::sharedAnimationCache();
	animCache->addAnimationsWithFile("");

	CCAnimation* whiteToBlack = animCache->animationByName(); 
	CCAnimation* blackToWhite = animCache->animationByName();
	
	m_WhiteToBlack = CCAnimate::create(whiteToBlack);
	m_BlackToWhite = CCAnimate::create(blackToWhite);

}
void ChessPiece::changeRole(enum Role role)
{
	//change to role
	if(m_pieceRole != role)
	{
		if(m_pieceRole == BLACK)			
		{
			m_piece->runAction(m_WhiteToBlack);	
		}
		else if(m_pieceRole == WHITE)
		{
			m_piece->runAction(m_BlackToWhite);	
		}
	
	}

}

