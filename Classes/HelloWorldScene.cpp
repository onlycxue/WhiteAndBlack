#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
  	if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));
	
	CCMenuItemImage *pSingalGameItem = CCMenuItemImage::create("singalButton.png",
															   "singalButton.png",
															   this,
															   menu_selector(HelloWorld::menuSingalCallback));

	pSingalGameItem->setPosition(ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));

	CCMenuItemImage *pMoreGameItem = CCMenuItemImage::create("moreButton.png",
															  "moreButton.png",
															  this,
															  menu_selector(HelloWorld::menuMoreCallback));

	pMoreGameItem->setPosition(ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2-200));														  
			// create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pSingalGameItem,pMoreGameItem,NULL);
//    pMenu->setPosition(CCPointZero);
//    this->addChild(pMenu, 1);
	pMenu->alignItemsVertically();

	//elastic effect
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	
	int i = 0;
	CCNode* child;
	CCArray* pArray = pMenu->getChildren();
	CCObject* pObject = NULL;
	CCARRAY_FOREACH(pArray,pObject)
	{
		if(pObject == NULL)	
			break;
		child = (CCNode*)pObject;
		CCPoint dstPoint = child->getPosition();
		int offset = (int)(s.width/2+50);
		if(i % 2 == 0)
			offset = -offset;
		child->setPosition(ccp(dstPoint.x+offset,dstPoint.y));
		child->runAction(CCEaseElasticOut::create(CCMoveBy::create(2,ccp(dstPoint.x-offset,0)),0.35f));
	
	}
	addChild(pMenu,1);
	pMenu->setPosition(ccp(s.width/2,s.height/2));

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    //CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    //pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
     //                       origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    //this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("startBackGround.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
// add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

void HelloWorld::menuSingalCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(GameScene::scene(GameScene::SingalMode));
}

void HelloWorld::menuMoreCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(GameScene::scene(GameScene::MoreMode));
}

