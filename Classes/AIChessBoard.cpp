/*
 * =====================================================================================
 *
 *       Filename:  AIChessBoard.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/13/2014 10:39:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "AIChessBoard.h"

bool AIChessBoard::init()
{
	if(!ChessBoardLayer::init())	
	{
		return false;	
	}
	return true;


}
void AIChessBoard::ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent)
{
	ChessBoardLayer::ccTouchesBegan(pTouches,pEvent);

}

