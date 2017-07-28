// DrawLine.cpp: implementation of the CDrawLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BaseDocViewDemo4.h"
#include "DrawLine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDrawLine::CDrawLine(CPoint pStar,CPoint pEnd)
{
	m_Star=pStar;
	m_End=pEnd;
}

CDrawLine::~CDrawLine()
{

}
void CDrawLine::Draw(CDC *pDC)
{
	pDC->MoveTo(m_Star.x,m_Star.y);							//绘制线条
	pDC->LineTo(m_End.x,m_End.y);
}

IMPLEMENT_SERIAL(CDrawLine,CObject,1)
CDrawLine::CDrawLine()									//不带参数的构造函数的实现
{
}

void CDrawLine::Serialize(CArchive &ar)//序列化函数的实现
{
	 if (ar.IsStoring())										//进行存档处理
	{
		// TODO: add storing code here
		ar<<m_Star<<m_End;
	}
	else												//进行读档处理
	{
		// TODO: add loading code here
		ar>>m_Star>>m_End;
	}
}
