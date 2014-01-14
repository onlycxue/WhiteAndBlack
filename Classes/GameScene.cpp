/*
 * =====================================================================================
 *
 *       Filename:  GameScene.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/11/2014 08:51:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "GameScene.h"

USING_NS_CC;

CCScene* GameScene::m_parentScene=NULL;
cocos2d::CCScene* GameScene::scene()
{
	CCScene *scene = CCScene::create();
	
	GameScene *layer = GameScene::create();
	scene->addChild(layer,1);
	m_parentScene=scene;
	//scene->addChild(GameScene::create());
	ChessBoardLayer* chessLayer = ChessBoardLayer::create();
	scene->addChild(chessLayer,0);
	return scene;
}

bool GameScene::init()
{
	if(!CCLayer::init())	
	{
		return false;	
	}
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
	//create back button
	CCMenuItemImage* backButton  = CCMenuItemImage::create(
										 "back.png",
										 "back.png",
										  this,
										  menu_selector(GameScene::menuBackCallback)
														);
	backButton->setPosition(ccp(origin.x+visibleSize.width-backButton->getContentSize().width/2,origin.y+visibleSize.height-backButton->getContentSize().height/2));
	
	CCMenu *pMenu = CCMenu::create(backButton,NULL);
	pMenu->setPosition(CCPointZero);
	addChild(pMenu,1);
	//add background
//	CCSprite* pSprite = CCSprite::create("gameBackGroud.png");
//	pSprite->setPosition(ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	

//	addChild(pSprite,0);
	return true;
}

void GameScene::menuBackCallback(CCObject* pSender)
{
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	CCRenderTexture* texture = CCRenderTexture::create(size.width,size.height);
	CCScene* contentScene = CCDirector::sharedDirector()->getRunningScene();
	texture->begin();
	contentScene->visit();
	texture->end();
	CCDirector::sharedDirector()->pushScene(SelectWindow::scene(texture));
	//addChild(SelectWindow::layer(),3);	

}
