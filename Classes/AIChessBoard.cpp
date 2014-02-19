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

//check 1
static int corner[][2] = {
	{0,0},
	{7,0},
	{7,7},
	{0,7}
};
static int side[][2] = {
	{2,0},	//top 
	{3,0},
	{4,0},
	{5,0},
	{7,2},	//right	
	{7,3},
	{7,4},
	{7,5},
	{2,7},  //bottom
	{3,7},	
	{4,7},
	{5,7},
	{0,2}, //left
	{0,3},
	{0,4},	
	{0,5},
};

static int sidein[][2] = {
	{2,1},	//top 
	{3,1},
	{4,1},
	{5,1},
	{6,2},	//right	
	{6,3},
	{6,4},
	{6,5},
	{2,6},  //bottom
	{3,6},	
	{4,6},
	{5,6},
	{1,2}, //left
	{1,3},
	{1,4},	
	{1,5},

};

static int cornerside[][2] = {
	{0,1},	//top left 
	{1,1},
	{1,0},
	{6,0},	//top right
	{6,1},	
	{7,1},
	{7,6}, //bottom right
	{6,6},
	{6,7},  
	{0,6}, //bottom left	
	{1,6},
	{1,7},
	
};



static int centreside[][2] = {
	{2,2}, //centretop
	{3,2},
	{4,2},
	{5,2}, //centretop
	{5,3},
	{5,4},
	{5,5}, //centrebottom
	{4,5},
	{3,5},
	{2,5}, //centreright
	{2,4},
	{2,3}

};
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
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	CCPoint point = touch->getLocation();	
//	CCLog("point:%f,%f",point.x,point.y);

	ChessCoordinate position;
	position = pixelToChessCoordinate(point);
	if(position.x >= 0 && position.x < 8 && position.y >= 0 && position.y < 8)
	{
			
		CCLOG("#currentRole:%d",getCurrentRole());
		
		CCLOG("position_x:%d,position_y:%d",position.x,position.y);
		int num = judgeRule(position.x,position.y,NULL,getCurrentRole());
		if(num != 0)
		{
				
			changeStore(getCurrentRole(),num);
			changeCurrentRole();	
			drawChessPiece();
			int num2 = AIjudge(getCurrentRole());	
			if(num2 > 0)
			{
				changeStore(getCurrentRole(),num);
				changeCurrentRole();
				drawChessPiece();	
			}

		}
	
	}

//	ChessBoardLayer::ccTouchesBegan(pTouches,pEvent);
//	int num = AIjudge(getCurrentRole());	
//	if(num > 0)
//	{
//		changeStore(getCurrentRole(),num);
//		changeCurrentRole();
//		drawChessPiece();	
//	}

}

int AIChessBoard::AIjudge(enum PieceStatus currentRole)
{
	//frist step
	for(int i = 0; i < 4; i++)
	{
		int num=judgeRule(corner[i][0],corner[i][1],NULL,currentRole);		
		if(num > 0)
		{
			
			return num;	
		}
	}
	//second step
	for (int i = 0; i < 16; i++)
	{
	int num = judgeRule(side[i][0],side[i][1],NULL,currentRole);
		if(num > 0)
		{
			return num;	
		}
	}
    //thrid step
	for (int i = 0; i < 12; i++)
	{
		int num = judgeRule(centreside[i][0],centreside[i][1],NULL,currentRole);
		if(num > 0)
		{
			return num;	
		}
	}
	//fouth step
	for (int i = 0; i < 16; i++)
	{
		int num = judgeRule(sidein[i][0],sidein[i][1],NULL,currentRole);
		if(num > 0)
		{
			return num;	
		}
	}
	//five
	for (int i = 0; i < 12; i++)
	{
		int num = judgeRule(cornerside[i][0],cornerside[i][1],NULL,currentRole);
		if(num > 0)
		{
			return num;	
		}
	}
	return 0;

}

