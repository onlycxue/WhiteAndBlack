/*
 * =====================================================================================
 *
 *       Filename:  StoreLayer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/14/2014 09:54:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "StoreLayer.h"

bool StoreLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	
	}

//	CCSize size = CCDirector::sharedDirector()->getVisibleSize();

	m_store = CCLabelTTF::create("00","Arial",32);
	addChild(m_store);

	m_time = CCLabelTTF::create("00","Arial",32);
	addChild(m_time);

	//addChild(getRole());
//	this->scheduleUpdate();	

	return true;


}

void StoreLayer::updateStore()
{
	char value[10];
	sprintf(value,"%d",_store);
	m_store->setString(value);

}

void StoreLayer::updateTime()
{
	char value[10];
	sprintf(value,"%d",_time);
	m_time->setString(value);

}

void StoreLayer::onExit()
{
//	m_store->release();
//	m_time->release();
	unscheduleUpdate();	

}

/*void StoreLayer::update(float dt)
{
	updateStore();
	updateTime();

}*/

//***********WhiteStoreLayer******************//

bool WhiteStoreLayer::init()
{
	if(!StoreLayer::init())
	{
		return false;	
	}
		
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	
	m_store->setPosition(ccp(150,size.height/2+100));
	m_time->setPosition(ccp(150,size.height/2-100));


	_Role = CCSprite::create("whitePiece.png");
	_Role->setPosition(ccp(150,size.height/2));
	addChild(_Role);
	

	return true;

}
//***********BlackStoreLayer************************//

bool BlackStoreLayer::init()
{
	if(!StoreLayer::init())
	{
		return false;	
	
	}

	CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	
	m_store->setPosition(ccp(size.width-150,size.height/2+100));
	m_time->setPosition(ccp(size.width-150,size.height/2-100));


	_Role = CCSprite::create("blackPiece.png");
	_Role->setPosition(ccp(size.width-150,size.height/2));
	addChild(_Role);

	return true;
}









































