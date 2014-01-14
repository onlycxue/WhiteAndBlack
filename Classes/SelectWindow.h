#ifndef _SELECTWINDOW_H_
#define _SELECTWINDOW_H_

#include "cocos2d.h"

class SelectWindow : public cocos2d::CCLayer
{
public:
	virtual bool init();

    static cocos2d::CCScene* scene(cocos2d::CCRenderTexture* bg);
	void menuContinueCallback();
	void menuExitCallback();
	CREATE_FUNC(SelectWindow);	

};



#endif
