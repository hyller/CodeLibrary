// DrawLine.h: interface for the CDrawLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWLINE_H__2B66E66D_5C37_4419_9E4D_9D049E6E2ADC__INCLUDED_)
#define AFX_DRAWLINE_H__2B66E66D_5C37_4419_9E4D_9D049E6E2ADC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDrawLine : public CObject  
{
public:
	CDrawLine(CPoint pStar,CPoint pEnd);					//构造函数
	virtual ~CDrawLine();
	void Draw(CDC *pDC);									//绘制直线
protected:
	CPoint m_Star,m_End;									//起点、终点坐标
};

#endif // !defined(AFX_DRAWLINE_H__2B66E66D_5C37_4419_9E4D_9D049E6E2ADC__INCLUDED_)
