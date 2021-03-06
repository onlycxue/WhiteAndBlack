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

 
bool ChessPiece::init()
{
	if(!CCSprite::init())
	{
		return false;	
	}
	animationInit();	
	m_pieceRole = EMPTYSTATUS;

	return true;

}
void ChessPiece::animationInit()
{
	m_frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	m_frameCache->addSpriteFramesWithFile("chesspiece_0.plist");
	
//	CCAnimationCache::purgeSharedAnimationCache();
//	CCAnimationCache *animCache = CCAnimationCache::sharedAnimationCache();
//	animCache->addAnimationsWithFile("");
	CCArray* animFrames = CCArray::createWithCapacity(2);
	char str[100];
	for(int i = 1;i < 3; i++ )
	{
		sprintf(str,"piece_%02d.png",i);
		CCSpriteFrame *frame = m_frameCache->spriteFrameByName(str); 
		animFrames->addObject(frame);
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
	m_WhiteToBlack->retain();
	m_BlackToWhite = CCAnimate::create(btw);
	m_BlackToWhite->retain();

}
void ChessPiece::changeRole(enum PieceStatus role)
{
	//change to role
		CCLog("changeRole!");

		if(role == BLACKSTATUS)			
		{	//m_WhiteToBlack
			m_pieceRole = BLACKSTATUS;
			this->runAction(m_WhiteToBlack);
		}
		else if(role == WHITESTATUS)
		{	//m_BlackToWhite
			m_pieceRole = WHITESTATUS;
			this->runAction(m_BlackToWhite);	
		}
	
}
PieceStatus ChessPiece::getPieceRole()
{
	return m_pieceRole;

}


//whiteChessPiece 

bool WhiteChessPiece::init()
{
	if(!ChessPiece::init())
	{
		return false;	
	}

	CCSpriteFrame *frame = m_frameCache->spriteFrameByName("piece_01.png");	
	this->setDisplayFrame(frame);
	m_pieceRole = WHITESTATUS; 
	return true;
	
}

//blackChessPiece

bool BlackChessPiece::init()
{
	if(!ChessPiece::init())
	{
		return false;	
	}
	CCSpriteFrame *frame = m_frameCache->spriteFrameByName("piece_02.png");
	this->setDisplayFrame(frame);
	m_pieceRole = BLACKSTATUS;
	return true;
}



