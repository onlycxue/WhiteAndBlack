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

int ChessBoardLayer::dir[8][2] = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}}; 

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
void ChessBoardLayer::chessBufInit()
{
	for(int i = 0; i < GRIDNUM; i++)
	{
		for(int j = 0; j < GRIDNUM; j++)	
		{
			chessBuf[i][j] = ChessBoardLayer::EMPTYSTATUS;	
		
		}
	
	}
	
	chessBuf[3][3] = ChessBoardLayer::WHITESTATUS; 
	chessBuf[4][4] = ChessBoardLayer::WHITESTATUS;
	chessBuf[3][4] = ChessBoardLayer::BLACKSTATUS;
	chessBuf[4][3] = ChessBoardLayer::BLACKSTATUS;

}

void ChessBoardLayer::ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent)
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	CCPoint point = touch->getLocation();	
	CCLog("point:%f,%f",point.x,point.y);
	//createPiece(point,WHITE);	
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

void ChessBoardLayer::createPiece(CCPoint point,enum PieceStatus role)
{

	ChessCoordinate position;
	position = pixelToChessCoordinate(point);
	if(position.x != -1 && position.y != -1)	
	{
		CCSprite* sprite = NULL;
		if(role == BLACKSTATUS)
		{
		//	sprite = CCSprite::create("blackPiece.png");
			//sprite->setPosition(ccp(STARTPOINT.x+x,SCREENSIZE.height-STARTPOINT.y+y));
			m_blackStore++;
			m_blackStatus->setStore(m_blackStore);
		}
		else if(role == WHITESTATUS)
		{
		//	sprite = CCSprite::create("whitePiece.png");
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

int ChessBoardLayer::judgeRule(int x,int y,void *chess,enum PieceStatus currentRole)
{
	if(x < 0 || x >=GRIDNUM || y < 0 || y >=GRIDNUM)
		return 0;
	int temp_x = x,temp_y = y;
	int i = 0,eatNum = 0;
	//typedef int (*p) [GRIDNUM];
	//p chessboard = p (chess);
	
	if(chessBuf[temp_x][temp_y] != ChessBoardLayer::EMPTYSTATUS)
		return 0;
	for(i = 0; i < 8 ; i++)
	{
		temp_x += dir[i][0];
		temp_y += dir[i][1];

		if((temp_x < GRIDNUM && temp_x >=0 && temp_y < GRIDNUM && temp_y >=0)
		 && (chessBuf[temp_x][temp_y] !=m_currentRole && chessBuf[temp_x][temp_y] != ChessBoardLayer::EMPTYSTATUS))
		 {
			temp_x += dir[i][0]; 
			temp_y += dir[i][1];

			while(temp_x < GRIDNUM && temp_x >=0 && temp_y < GRIDNUM && temp_y >=0)
			{
				if(chessBuf[temp_x][temp_y] == ChessBoardLayer::EMPTYSTATUS)	
					break;
				if(chessBuf[temp_x][temp_y] == m_currentRole)
				{
					chessBuf[temp_x][temp_y] = m_currentRole;
					temp_x -= dir[i][0];
					temp_y -= dir[i][1];

					while((temp_x != x) || (temp_y != y))
					{
						chessBuf[temp_x][temp_y] = m_currentRole;
						temp_x -= dir[i][0];
						temp_y -= dir[i][1];
						eatNum++;
					}
					break;
				
				}
				temp_x += dir[i][0];
				temp_y += dir[i][1];
			
			}
		 
		 
		 }

	
	temp_x = x; 
	temp_y = y;	
	}
	
	return eatNum;
}

CCString* ChessBoardLayer::makeKey(int x, int y)
{
	char key[10];
	sprintf(key,"%d%d",x,y);
	return CCString::create(key);
}

void ChessBoardLayer::update(float dt)
{
	m_whiteStatus->updateStore();
	m_blackStatus->updateStore();
	
//	int x , y;
//	for(x = 0 ; x < GRIDNUM; x++)
//	{
//		for(y = 0; y < GRIDNUM; y++)	
//		{
//			if(chessBuf[x][y] == ChessBoardLayer::EMPTYSTATUS)		
//			{
////				break;	
//			}
//			else if (chessBuf[x][y] == ChessBoardLayer::BLACKSTATUS)
//			{
//						
//			}
//		
//		}
//	
//	}
	
		

}

