#ifndef _DEFINE_H_
#define _DEFINE_H_


#define STARTPOINT ccp(320,680)
#define ENDPOINT ccp(960,40)
#define PIECESIZE CCSizeMake(80,80)
#define SCREENSIZE CCSizeMake(1280,720)
#define GRIDNUM 8

enum PieceStatus
{
	EMPTYSTATUS,
	BLACKSTATUS,
	WHITESTATUS,
};

#endif
