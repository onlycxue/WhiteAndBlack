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
	
	//dictionary for chesspiece;
//	m_chessPieceDic = CCDictionary::create();
	
	chessBufInit();
	setTouchEnabled(true);
	this->scheduleUpdate();
	m_currentRole =	BLACKSTATUS;
	return true;


}
void ChessBoardLayer::chessBufInit()
{
	for(int i = 0; i < GRIDNUM; i++)
	{
		for(int j = 0; j < GRIDNUM; j++)	
		{
			chessBuf[i][j] = EMPTYSTATUS;	
		
		}
	
	}
	
	chessBuf[3][3] = WHITESTATUS; 
	chessBuf[4][4] = WHITESTATUS;
	chessBuf[3][4] = BLACKSTATUS;
	chessBuf[4][3] = BLACKSTATUS;

	createPiece(3,3,WHITESTATUS);
	createPiece(4,4,WHITESTATUS);
	createPiece(3,4,BLACKSTATUS);
	createPiece(4,3,BLACKSTATUS);
//	createPiece(3,5,BLACKSTATUS);
//	getPieceFromDic(3,4)->changeRole(WHITESTATUS);


}

void ChessBoardLayer::ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent)
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	CCPoint point = touch->getLocation();	
//	CCLog("point:%f,%f",point.x,point.y);

	ChessCoordinate position;
	position = pixelToChessCoordinate(point);
	if(position.x >= 0 && position.x < 8 && position.y >= 0 && position.y < 8)
	{
			
		CCLOG("#currentRole:%d",m_currentRole);
		
		CCLOG("position_x:%d,position_y:%d",position.x,position.y);
		int num = judgeRule(position.x,position.y,NULL,m_currentRole);
		if(num != 0)
		{
				
			changeStore(m_currentRole,num);
			changeCurrentRole();	
			drawChessPiece();
		}
	
	}
//	getPieceFromDic(3,4)->changeRole(WHITESTATUS);



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


void ChessBoardLayer::createPiece(int x,int y,enum PieceStatus role)
{
	if((x != -1 && y!=-1 )&&( x<=GRIDNUM && y<=GRIDNUM))
	{
		
		CCLOG("now in createPiece!");
		if(role == BLACKSTATUS)	
		{
//			CCLOG("blackStatus!");
			m_chessPiece = BlackChessPiece::create();	
		//	m_blackStore++;		
		//	m_blackStatus->setStore(m_blackStore);
			m_blackStatus->addStore(1);
			int pixel_x = x*PIECESIZE.width + PIECESIZE.width/2; 
			int pixel_y = (GRIDNUM - y)*PIECESIZE.height + PIECESIZE.height/2;
			m_chessPiece->setPosition(ccp(STARTPOINT.x+pixel_x,pixel_y-(SCREENSIZE.height - STARTPOINT.y)));
			addChild(m_chessPiece);
			//m_chessPiece->retain();
			DicAddChild(x,y,m_chessPiece);
			SimpleAudioEngine::sharedEngine()->playEffect(EFFECT_FILE,true);

		}
		else if(role == WHITESTATUS)
		{
//			CCLOG("whiteStatus!");
			m_chessPiece = WhiteChessPiece::create();
		//	m_whiteStore++;	
		//	m_whiteStatus->setStore(m_whiteStore);
			m_whiteStatus->addStore(1);
			int pixel_x = x*PIECESIZE.width + PIECESIZE.width/2; 
			int pixel_y = (GRIDNUM - y)*PIECESIZE.height + PIECESIZE.height/2;
			m_chessPiece->setPosition(ccp(STARTPOINT.x+pixel_x,pixel_y-(SCREENSIZE.height - STARTPOINT.y)));
			addChild(m_chessPiece);
			//m_chessPiece->retain();
			DicAddChild(x,y,m_chessPiece);
			SimpleAudioEngine::sharedEngine()->playEffect(EFFECT_FILE,true);

		}
			
	}


}


void ChessBoardLayer::DicAddChild(int x,int y,ChessPiece *piece)
{
	std::string str = makeKey(x,y);
	std::cout << str << std::endl;
//	m_chessPieceDic->setObject(piece,str.c_str());
	piece->retain();
	m_chessPieceDic[str] = piece;

}

ChessPiece* ChessBoardLayer::getPieceFromDic(int x,int y)
{
//	return (ChessPiece*)m_chessPieceDic->objectForKey(makeKey(x,y));
	ChessPieceDic::iterator it;
	it = m_chessPieceDic.find(makeKey(x,y));
	if(it == m_chessPieceDic.end())
	{
		return NULL;	
	}
	return it->second;

}

void ChessBoardLayer::setCurrentRole(PieceStatus role)	
{
	m_currentRole = role;
}

void ChessBoardLayer::changeCurrentRole()
{
	if(m_currentRole == WHITESTATUS)
	{
		setCurrentRole(BLACKSTATUS);	
	}
	else if(m_currentRole == BLACKSTATUS)
	{
		setCurrentRole(WHITESTATUS);	
	
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
	
	if(chessBuf[temp_x][temp_y] != EMPTYSTATUS)
		return 0;
	for(i = 0; i < 8 ; i++)
	{
//		CCLOG("8 dir entry!");
		temp_x += dir[i][0];
		temp_y += dir[i][1];

		CCLOG("dir temp_x:%d,temp_y:%d,ChessBuf:%d",temp_x,temp_y,chessBuf[temp_x][temp_y]);
		
		if((temp_x < GRIDNUM && temp_x >=0 && temp_y < GRIDNUM && temp_y >=0)
		 && (chessBuf[temp_x][temp_y] !=currentRole && chessBuf[temp_x][temp_y] != EMPTYSTATUS))
		 {
		 	CCLOG("if entry!");
			temp_x += dir[i][0]; 
			temp_y += dir[i][1];
			
			while(temp_x < GRIDNUM && temp_x >=0 && temp_y < GRIDNUM && temp_y >=0)
			{
				CCLOG("positionStatus:%d,currentRole:%d",chessBuf[temp_x][temp_y],currentRole);
				if(chessBuf[temp_x][temp_y] == EMPTYSTATUS)	
					break;
				if(chessBuf[temp_x][temp_y] == currentRole)
				{

//					CCLOG("now in while##");
					chessBuf[temp_x][temp_y] = currentRole;
					//addChessPiece
					//createPiece(temp_x,temp_y,m_currentRole);
					temp_x -= dir[i][0];
					temp_y -= dir[i][1];

					while((temp_x != x) || (temp_y != y))
					{
						chessBuf[temp_x][temp_y] = currentRole;
						//addchesspiece
				//		getPieceFromDic(temp_x,temp_y)->changeRole(currentRole);
						
//						CCLOG("temp_x:%d,temp_y:%d",temp_x,temp_y);
						temp_x -= dir[i][0];
						temp_y -= dir[i][1];
						eatNum++;
					}
					chessBuf[temp_x][temp_y] = currentRole;
				//		createPiece(temp_x,temp_y,currentRole);
				//	CCLOG("temp_x:%d,temp_y:%d",temp_x,temp_y);
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

std::string ChessBoardLayer::makeKey(int x, int y)
{
	char key[10];
	sprintf(key,"%d%d",x,y);
	return key;
}

void ChessBoardLayer::changeStore(PieceStatus role,int num)
{
	if(role == WHITESTATUS)
	{
		m_whiteStatus->addStore(num);
		m_blackStatus->subStore(num);
	}
	else if(role == BLACKSTATUS)
	{
		m_whiteStatus->subStore(num);
		m_blackStatus->addStore(num);
	}

}

void ChessBoardLayer::drawChessPiece()
{
	int x = 0,y = 0;
	for(x = 0 ; x < 8 ; x++)
	{
		for(y = 0; y < 8 ; y++)	
		{
			if(chessBuf[x][y] == EMPTYSTATUS)		
				continue;
			ChessPiece *ptr = getPieceFromDic(x,y);
			if(ptr == NULL)
			{
				createPiece(x,y,(PieceStatus)chessBuf[x][y]);	

			}
			else
			{
				if(ptr->getPieceRole() != chessBuf[x][y])	
					ptr->changeRole((PieceStatus)chessBuf[x][y]);	
			}
		
		}
	}

}

void ChessBoardLayer::update(float dt)
{
	m_whiteStatus->updateStore();
	m_blackStatus->updateStore();
	
}

