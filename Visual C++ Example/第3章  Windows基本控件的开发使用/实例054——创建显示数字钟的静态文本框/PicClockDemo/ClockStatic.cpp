// ClockStatic.cpp : implementation file
//

#include "stdafx.h"
#include "PicClockDemo.h"
#include "ClockStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClockStatic
//COLORREF CClockStatic::origin=RGB(255,0,0);
CClockStatic::CClockStatic()
{
	for(int i=0;i<12;i++)
	{
		HBITMAP temp;
		temp=(HBITMAP)::CreateMappedBitmap(AfxGetApp()->m_hInstance,i+IDB_BITMAP0,0,NULL,0);
		m_hBitmap[i]=(HBITMAP)::CopyImage(temp,IMAGE_BITMAP,0,0,LR_COPYRETURNORG|LR_COPYDELETEORG);//载入位图
	}
}

CClockStatic::~CClockStatic()
{
	for(int i=0;i<11;i++)
	{
		if(m_hBitmap[i])
			::DeleteObject(m_hBitmap[i]);
	}
}


BEGIN_MESSAGE_MAP(CClockStatic, CStatic)
	//{{AFX_MSG_MAP(CClockStatic)
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClockStatic message handlers

void CClockStatic::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	m_nTimer=SetTimer(1,1000,NULL);//设置时钟
	::GetObject(m_hBitmap[0],sizeof BITMAP,&m_bm);
	CStatic::PreSubclassWindow();
}

BOOL CClockStatic::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CBrush brush;
	brush.CreateSolidBrush(::GetSysColor(COLOR_WINDOWTEXT));
	CBrush* pOldBrush=pDC->SelectObject(&brush);
	CRect rectClient;
	GetClientRect(&rectClient);
	pDC->PatBlt(0,0,rectClient.Width(),rectClient.Height(),PATCOPY);
	pDC->SelectObject(pOldBrush);
	return CStatic::OnEraseBkgnd(pDC);
}

void CClockStatic::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==m_nTimer)
	{
		CRect rectClient;
		GetClientRect(&rectClient);//获取静态框客户区域
		m_Height=rectClient.Height();
		m_Width=rectClient.Width()/8;//要显示8个位图
		CTime time=CTime::GetCurrentTime();//获取当前时间
		int nh1=time.GetHour()/10;//小时的第一位
		ShowPic(nh1,0);
		int nh2=time.GetHour()%10;//小时的第二位
		ShowPic(nh2,1);
		int nm1=time.GetMinute()/10;//分钟的第一位
		ShowPic(nm1,3);
		int nm2=time.GetMinute()%10;//分钟的第二位
		ShowPic(nm2,4);
		int ns1=time.GetSecond()/10;//秒的第一位
		ShowPic(ns1,6);
		int ns2=time.GetSecond()%10;//秒的第二位
		ShowPic(ns2,7);		
		ShowPic(10,2);//显示“：”
		ShowPic(10,5);
	}
	CStatic::OnTimer(nIDEvent);
}

void CClockStatic::OnDestroy() 
{
	CStatic::OnDestroy();
	KillTimer(m_nTimer);//销毁时钟
	// TODO: Add your message handler code here
	
}

void CClockStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CStatic::OnPaint() for painting messages
}

void CClockStatic::ShowPic(UINT digit,UINT pos)
{
	CClientDC dc(this);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);//创建内存DC
	CBitmap* pBitmap=CBitmap::FromHandle(m_hBitmap[digit]);//获取位图
	CBitmap* pOldBitmap=dcMem.SelectObject(pBitmap);
	//从内存钟复制位图并缩放用指定尺寸显示
	dc.StretchBlt(m_Width*pos,0,m_Width,m_Height,&dcMem,0,0,m_bm.bmWidth,m_bm.bmHeight,SRCCOPY);
	dcMem.SelectObject(pOldBitmap);
	dcMem.DeleteDC();
}
