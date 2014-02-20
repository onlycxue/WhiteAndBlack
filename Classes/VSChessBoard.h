#ifndef  _VSCHESSBOARD_H_
#define	_VSCHESSBOARD_H_			/*  */

#include "ChessBoardLayer.h"

class VSChessBoard: public ChessBoardLayer
{
	public:
		virtual bool init();	
		virtual void ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent);
		
		CREATE_FUNC(VSChessBoard);
	protected:

	private:



};

#endif     /* -----  not _VSCHESSBOARD_H_  ----- */
