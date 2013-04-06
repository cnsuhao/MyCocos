//--------------------------------------------------------------------
#ifndef _CCButtonSprite_h_
#define _CCButtonSprite_h_
//--------------------------------------------------------------------
#include "cocos2d.h"
//--------------------------------------------------------------------
NS_CC_BEGIN
class CCButtonSprite : public CCSprite, public CCTouchDelegate
{
public:
	CCButtonSprite();
	virtual ~CCButtonSprite();

	bool InitButtonSprite(const char* pszImageFileName);

protected:
	//From cocos2d::CCTouchDelegate
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	//
	void OnActionFinish();

protected:
	//���ؼ�Ҫʵ�ֵ�Ч���ǣ��ؼ��Ŵ�ֱ�������������ڣ�Ȼ������С����ʼ��С��
	enum eTransformState
	{
		Transform_None,
		Transform_Large,
		Transform_WaitForRestore,
		Transform_Restore,
	};

private:
	eTransformState m_eTransformState;

};
NS_CC_END
//--------------------------------------------------------------------
#endif //_CCButtonSprite_h_
//--------------------------------------------------------------------
