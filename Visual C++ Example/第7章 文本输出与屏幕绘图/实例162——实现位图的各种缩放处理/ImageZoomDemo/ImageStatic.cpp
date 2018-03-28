// ImageStatic.cpp : implementation file
//

#include "stdafx.h"
#include "ImageZoomDemo.h"
#include "ImageStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageStatic

CImageStatic::CImageStatic()
{
	m_Type =0;
}

CImageStatic::~CImageStatic()
{
}


BEGIN_MESSAGE_MAP(CImageStatic, CStatic)
	//{{AFX_MSG_MAP(CImageStatic)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageStatic message handlers
void CImageStatic::SetImage(UINT resID)
{
	m_bmp.LoadBitmap(resID);//加载位图
}
void CImageStatic::SetType(int nType)
{
	m_Type =  nType;	
	Invalidate();//重绘控件窗口
}

void CImageStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting	
	// TODO: Add your message handler code here
	CRect r;
	GetClientRect(&r);	//获得控件客户窗口大小
	HBRUSH brush = (HBRUSH)::GetStockObject(GRAY_BRUSH); 
	::FillRect(dc.m_hDC,&r,brush);//填充背景
	dc.SetStretchBltMode(HALFTONE);
	//将位图选进内存DC中
	CDC memdc;
	memdc.CreateCompatibleDC( &dc );
	CBitmap* pOldBmp= memdc.SelectObject(&m_bmp);
	//获得位图参数
	BITMAP bmp;
	m_bmp.GetBitmap(&bmp);
	switch(m_Type)//开始缩放
	{
	case 0://原始大小
			dc.BitBlt(r.left,r.top,r.Width(),r.Height(),&memdc,0,0,SRCCOPY);
		break;
	case 1://按宽度
		dc.StretchBlt(r.left,r.top,r.Width(),bmp.bmHeight,&memdc,0,0,
			bmp.bmWidth,bmp.bmHeight,SRCCOPY);
		break;
	case 2://按高度
		dc.StretchBlt(r.left,r.top,bmp.bmWidth,r.Height(),&memdc,0,0,
			bmp.bmWidth,bmp.bmHeight,SRCCOPY);
		break;
	case 3://充满窗口
		dc.StretchBlt(r.left,r.top,r.Width(),r.Height(),&memdc,0,0,
			bmp.bmWidth,bmp.bmHeight,SRCCOPY);
		break;
	case 4://居中显示，大小为窗口的一半
		dc.StretchBlt(r.Width()/4,r.Height()/4,r.Width()/2,r.Height()/2,&memdc,0,0,
			bmp.bmWidth,bmp.bmHeight,SRCCOPY);
		break;
	}
	memdc.SelectObject(pOldBmp);//还原画刷
	// Do not call CStatic::OnPaint() for painting messages
}
