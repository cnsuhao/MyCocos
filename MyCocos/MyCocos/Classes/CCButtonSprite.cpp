//--------------------------------------------------------------------
#include "CCButtonSprite.h"
//--------------------------------------------------------------------
NS_CC_BEGIN
//--------------------------------------------------------------------
CCButtonSprite::CCButtonSprite()
:m_eTransformState(Transform_None)
{

}
//--------------------------------------------------------------------
CCButtonSprite::~CCButtonSprite()
{

}
//--------------------------------------------------------------------
bool CCButtonSprite::InitButtonSprite(const char* pszImageFileName)
{
	if (!initWithFile(pszImageFileName))
	{
		return false;
	}
	//设置为自动释放的对象。
	autorelease();
	//以图片的左上角作为锚点。
	setAnchorPoint(CCPoint(0.0f, 1.0f));
	//注册Touch操作事件响应。
	CCTouchDispatcher* pDispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
	pDispatcher->addTargetedDelegate(this, 0, true);
	//
	return true;
}
//--------------------------------------------------------------------
bool CCButtonSprite::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	bool br = false;
	//判断Touch坐标是否落在本控件内部。
	CCPoint touchLocation = pTouch->getLocation();
	CCPoint local = convertToNodeSpace(touchLocation);
	if (local.x > 0.0f && local.x < m_tContentSize.width)
	{
		if (local.y > 0.0f && local.y < m_tContentSize.height)
		{
			br = true;
		}
	}
	if (!br)
	{
		return br;
	}

	//缩放变化持续的时长。
	float fInterval = 3.0f;
	//放大多少倍。
	float fBeiShu = 2.0f;
	//
	switch (m_eTransformState)
	{
	case Transform_None:
		{
			m_eTransformState = Transform_Large;
			CCActionInterval* action = (CCActionInterval*)CCSequence::create(
				CCScaleBy::create(fInterval, fBeiShu),
				CCCallFunc::create(this, callfunc_selector(CCButtonSprite::OnActionFinish)), 
				NULL);
			runAction(action);
		}
		break;
	case Transform_Large:
		{
			//什么都不做。
		}
		break;
	case Transform_WaitForRestore:
		{
			m_eTransformState = Transform_Restore;
			CCActionInterval* action = (CCActionInterval*)CCSequence::create(
				CCScaleBy::create(fInterval, 1.0f/fBeiShu),
				CCCallFunc::create(this, callfunc_selector(CCButtonSprite::OnActionFinish)), 
				NULL);
			runAction(action);
		}
		break;
	case Transform_Restore:
		{
			//什么都不做。
		}
		break;
	default:
		break;
	}
	return br;
}
//--------------------------------------------------------------------
void CCButtonSprite::OnActionFinish()
{
	switch (m_eTransformState)
	{
	case Transform_None:
		{
			//什么都不做。
		}
		break;
	case Transform_Large:
		{
			m_eTransformState = Transform_WaitForRestore;
		}
		break;
	case Transform_WaitForRestore:
		{
			//什么都不做。
		}
		break;
	case Transform_Restore:
		{
			m_eTransformState = Transform_None;
		}
		break;
	default:
		break;
	}
}
//--------------------------------------------------------------------
NS_CC_END
//--------------------------------------------------------------------
