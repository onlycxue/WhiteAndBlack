/*
 * =====================================================================================
 *
 *       Filename:  VSChessBoard.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/13/2014 09:46:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "VSChessBoard.h"

bool VSChessBoard::init()
{
	if(!ChessBoardLayer::init());
	{
		return false;
	}

	return true;



}

void VSChessBoard::ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent)
{
	

}


