/*
 * =====================================================================================
 *
 *       Filename:  SelectWindow.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/11/2014 06:56:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "SelectWindow.h"

USING_NS_CC;
bool SelectWindow::init()
{
	if(!CCLayer::init())
	{
		return false;
	}
	
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCMenuItemImage* continueGameButton = CCMenuItemImage::create("continueButton.png",
																 "continueButton.png",
																 this,
																 menu_selector(SelectWindow::menuContinueCallback));	
	

	continueGameButton->setPosition(ccp(visibleSize.width/2-20,visibleSize.height/2+100));
	CCMenuItemImage* exitGameButton = CCMenuItemImage::create("exitButton.png",
															  "exitButton.png",
															  this,
															  menu_selector(SelectWindow::menuExitCallback));
	 															  
	exitGameButton->setPosition(ccp(visibleSize.width/2-20,visibleSize.height/2-100));
	CCMenu* menu = CCMenu::create(continueGameButton,exitGameButton,NULL);
	menu->setPosition(CCPointZero);
	addChild(menu,1);

	CCSprite* pSprite = CCSprite::create("selectWindow.png");
	pSprite->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
	addChild(pSprite);

	return true;
}

cocos2d::CCScene* SelectWindow::scene(cocos2d::CCRenderTexture* bg)
{
	CCScene* scene = CCScene::create();

	CCSprite* bgSprite = CCSprite::createWithTexture(bg->getSprite()->getTexture());
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	bgSprite->setPosition(ccp(size.width/2,size.height/2));
	bgSprite->setFlipY(true);
	scene->addChild(bgSprite,0);

	SelectWindow* window = SelectWindow::create();

	scene->addChild(window,1);

	return scene;

}

void SelectWindow::menuContinueCallback()
{
	CCDirector::sharedDirector()->popScene();


}

void SelectWindow::menuExitCallback()
{

	CCDirector::sharedDirector()->end();
}
