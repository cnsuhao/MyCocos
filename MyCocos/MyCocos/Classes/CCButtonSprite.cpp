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
	//����Ϊ�Զ��ͷŵĶ���
	autorelease();
	//��ͼƬ�����Ͻ���Ϊê�㡣
	setAnchorPoint(CCPoint(0.0f, 1.0f));
	//ע��Touch�����¼���Ӧ��
	CCTouchDispatcher* pDispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
	pDispatcher->addTargetedDelegate(this, 0, true);
	//
	return true;
}
//--------------------------------------------------------------------
bool CCButtonSprite::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	bool br = false;
	//�ж�Touch�����Ƿ����ڱ��ؼ��ڲ���
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

	//���ű仯������ʱ����
	float fInterval = 3.0f;
	//�Ŵ���ٱ���
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
			//ʲô��������
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
			//ʲô��������
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
			//ʲô��������
		}
		break;
	case Transform_Large:
		{
			m_eTransformState = Transform_WaitForRestore;
		}
		break;
	case Transform_WaitForRestore:
		{
			//ʲô��������
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
