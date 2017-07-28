// DrawLine.cpp: implementation of the CDrawLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BaseDocViewDemo2.h"
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
	pDC->MoveTo(m_Star.x,m_Star.y);							//»æÖÆÏßÌõ
	pDC->LineTo(m_End.x,m_End.y);
}

