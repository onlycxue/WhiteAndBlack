#ifndef  _AICHESSBOARD_H_
#define	 _AICHESSBOARD_H_			/*  */

#include "ChessBoardLayer.h"
#include "define.h"

class AIChessBoard:public ChessBoardLayer
{
	public:
		virtual bool init();
		virtual void ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent);
		int AIjudge(enum PieceStatus currentRole);

		CREATE_FUNC(AIChessBoard);
	protected:

	private:

}; /* -----  end of class AIChessBoard  ----- */


#endif     /* -----  not _AICHESSBOARD_H_  ----- */
