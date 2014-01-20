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

	m_piece = ChessPiece::create();
	CCSpriteFrame *frame = m_frameCache->spriteFrameByName("piece_01.png");	
	m_piece->setDisplayFrame(frame);
	m_pieceRole = WHITESTATUS; 
	return m_piece;
}

ChessPiece* ChessPiece::createBlackPiece()
{
	animationInit();

	m_piece = ChessPiece::create();
	CCSpriteFrame *frame = m_frameCache->spriteFrameByName("piece_02.png");	
	m_piece->setDisplayFrame(frame);
	m_pieceRole = BLACKSTATUS;

	return m_piece;
} 
void ChessPiece::animationInit()
{
	m_frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	m_frameCache->addSpriteFramesWithFile("");
	
//	CCAnimationCache::purgeSharedAnimationCache();
//	CCAnimationCache *animCache = CCAnimationCache::sharedAnimationCache();
//	animCache->addAnimationsWithFile("");
	CCArray* animFrames = CCArray::createWithCapacity(2);
	char str[100];
	for(int i = 1;i < 3; i++ )
	{
		sprintf(str,"piece_%02d.png",i);
		CCSpriteFrame *frame = m_frameCache->spriteFrameByName(str); animFrames->addObject(frame);
	}
	CCAnimation *whiteToBlack = CCAnimation::createWithSpriteFrames(animFrames,0.2f);
	CCAnimationCache::sharedAnimationCache()->addAnimation(whiteToBlack,"whiteToBlack");
	animFrames->removeAllObjects();
	
	for(int i = 2; i > 0; i--)
	{
		sprintf(str,"piece_%02d.png",i);
		CCSpriteFrame * frame = m_frameCache->spriteFrameByName(str);
		animFrames->addObject(frame);
	
	}
	CCAnimation *blackToWhite = CCAnimation::createWithSpriteFrames(animFrames,0.2f);
	CCAnimationCache::sharedAnimationCache()->addAnimation(blackToWhite,"blackToWhite");
	animFrames->removeAllObjects();

//	CCAnimation* whiteToBlack = animCache->animationByName(); 
//	CCAnimation* blackToWhite = animCache->animationByName();
	CCAnimationCache *animCache = CCAnimationCache::sharedAnimationCache();
	CCAnimation* btw = animCache->animationByName("blackToWhite");
	CCAnimation* wtb = animCache->animationByName("whiteToBlack");

	m_WhiteToBlack = CCAnimate::create(wtb);
	m_BlackToWhite = CCAnimate::create(btw);

}
void ChessPiece::changeRole(enum PieceStatus role)
{
	//change to role
	if(m_pieceRole != role)
	{
		if(m_pieceRole == BLACKSTATUS)			
		{
			m_piece->runAction(m_WhiteToBlack);	
		}
		else if(m_pieceRole == WHITESTATUS)
		{
			m_piece->runAction(m_BlackToWhite);	
		}
	
	}

}

