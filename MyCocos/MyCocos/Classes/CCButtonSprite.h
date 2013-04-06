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
	//本控件要实现的效果是，控件放大，直至撑满整个窗口，然后再缩小到初始大小。
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
