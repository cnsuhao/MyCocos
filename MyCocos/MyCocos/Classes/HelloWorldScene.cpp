#include "HelloWorldScene.h"
#include "SoStringHelp.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	m_pSprite = NULL;
	m_pButtonSprite = NULL;
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.

        // Create a "close" menu item with close icon, it's an auto release object.
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
		const char* pszMyWords = "Hello World 尤建喜";
		char* pConvertWords = SoComponent::AnsiToUtf8(pszMyWords);
        CCLabelTTF* pLabel = CCLabelTTF::create(pConvertWords, "simhei.ttf", 24); //"Arial"
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 50));

        // Add the label to HelloWorld layer as a child layer.
        this->addChild(pLabel, 1);

        // 3. Add add a splash screen, show the cocos2d splash image.
        CCSprite* pSprite = CCSprite::create("HelloWorld.png");
        CC_BREAK_IF(! pSprite);

		//以图片的左上角作为锚点。
		pSprite->setAnchorPoint(CCPoint(0.0f, 1.0f));
        // Place the sprite on the center of the screen
        //pSprite->setPosition(ccp(size.width/2, size.height/2));
		pSprite->setPosition(CCPoint(0.0f, size.height));

		//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		//CCActionInterval* action = CCScaleBy::create(3, 2);
		////CCActionInterval* action_back = action->reverse();
		////CCActionInterval* seq = (CCActionInterval*)(CCSequence::create( action, action_back, NULL ));

		////pSprite->runAction( CCRepeatForever::create(seq) );

		//pSprite->runAction(action);
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


        // Add the sprite to HelloWorld layer as a child layer.
        this->addChild(pSprite, 0);
		m_pSprite = pSprite;


		//CCSprite* pSprite_2 = CCSprite::create("HelloWorld.png");
		//CC_BREAK_IF(! pSprite_2);

		//// Place the sprite on the center of the screen
		//pSprite_2->setPosition(ccp(size.width/2-10.0f, size.height/2));
		//this->addChild(pSprite_2, -10);

		m_pButtonSprite = new CCButtonSprite;
		m_pButtonSprite->InitButtonSprite("HelloWorld.png");
		m_pButtonSprite->setPosition(CCPoint(0.0f, size.height));
		this->addChild(m_pButtonSprite, 0);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    //// "close" menu item clicked
    //CCDirector::sharedDirector()->end();

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	CCActionInterval* action = CCScaleBy::create(3, 2);
	//CCActionInterval* action_back = action->reverse();
	//CCActionInterval* seq = (CCActionInterval*)(CCSequence::create( action, action_back, NULL ));

	//pSprite->runAction( CCRepeatForever::create(seq) );

	m_pSprite->runAction(action);
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

