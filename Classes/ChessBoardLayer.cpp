/*
 * =====================================================================================
 *
 *       Filename:  ChessBoardLayer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/13/2014 09:31:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "ChessBoardLayer.h"

USING_NS_CC;

bool ChessBoardLayer::init()
{
	if(!CCLayer::init())
	{
		return false;	
	
	}

	CCSize visible = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *pSprite = CCSprite::create("gameBackGroud.png");
	pSprite->setPosition(ccp(visible.width/2,visible.height/2));
	addChild(pSprite);

	m_whiteStatus = WhiteStoreLayer::create(); 
	addChild(m_whiteStatus);

	m_blackStatus = BlackStoreLayer::create();
	addChild(m_blackStatus);


	setTouchEnabled(true);
	m_whiteStore = 0;
	m_blackStore = 0;
	this->scheduleUpdate();
	return true;


}
void ChessBoard::chessBufInit()
{
	for(int i = 0; i < GRIDNUM; i++)
	{
		for(int j = 0; j < GRIDNUM; j++)	
		{
			chessBuf[i][j] = ChessBoard::EMPTY;	
		
		}
	
	}
	chessBuf[3][3] = ChessBoard::WHITE;
	chessBuf[4][4] = ChessBoard::WHITE;
	chessBuf[3][4] = ChessBoard::BLACK;
	chessBuf[4][3] = ChessBoard::BLACK;

}
void ChessBoard::chessDirInit()
{
	// 8 dir

	dir[0][2] = {1,0};
	dir[1][2] = {1,-1};
	dir[2][2] = {0,-1};
	dir[3][2] = {-1,-1};
	dir[4][2] = {-1,0};
	dir[5][2] = {-1,1};
	dir[6][2] = {0,1};
	dir[7][2] = {1,1};

}

void ChessBoardLayer::ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent)
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	CCPoint point = touch->getLocation();	
	CCLog("point:%f,%f",point.x,point.y);
	createPiece(point,ChessBoardLayer::WHITE);	
}

ChessCoordinate ChessBoardLayer::pixelToChessCoordinate(CCPoint point)
{
	
	ChessCoordinate position;
	if((point.x > STARTPOINT.x && point.x < ENDPOINT.x)&&(point.y< STARTPOINT.y && point.y > ENDPOINT.y))
	{	
		position.x = ((int)point.x-STARTPOINT.x)/PIECESIZE.width;	
		position.y = (STARTPOINT.y-(int)point.y)/PIECESIZE.height;
		return position;			
	
	}
	else
	{
		position.x = -1;	
		position.y = -1;

	}
		return position;

}

void ChessBoardLayer::createPiece(CCPoint point,enum Role role)
{

	ChessCoordinate position;
	position = pixelToChessCoordinate(point);
	if(position.x != -1 && position.y != -1)	
	{
		CCSprite* sprite = NULL;
		if(role == ChessBoardLayer::BLACK)
		{
			sprite = CCSprite::create("blackPiece.png");
			//sprite->setPosition(ccp(STARTPOINT.x+x,SCREENSIZE.height-STARTPOINT.y+y));
			m_blackStore++;
			m_blackStatus->setStore(m_blackStore);
		}
		else
		{
			sprite = CCSprite::create("whitePiece.png");
			m_whiteStore++;
			m_whiteStatus->setStore(m_whiteStore);
		
		}
		int x = position.x * PIECESIZE.width + PIECESIZE.width/2;
		int y = (8-position.y)*PIECESIZE.height + PIECESIZE.height/2; 
		//sprite->setPosition(ccp(STARTPOINT.x+x,SCREENSIZE.height-STARTPOINT.y+y));
		sprite->setPosition(ccp(STARTPOINT.x+x,y-(SCREENSIZE.height-STARTPOINT.y)));
		addChild(sprite);
	
	}

}

CCString ChessBoardLayer::makeKey(int x, int y)
{
	char key[10];
	sprintf(key,"%d%d",x,y);
	return CCString::create(key);
}

void ChessBoardLayer::update(float dt)
{
	m_whiteStatus->updateStore();
	m_blackStatus->updateStore();


}

