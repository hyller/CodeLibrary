// RulerView.cpp : implementation file
//

#include "stdafx.h"
#include "RadarDataShow.h"
#include "RulerView.h"
#include "RullerSplliterWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRulerView

IMPLEMENT_DYNCREATE(CRulerView, CView)

CRulerView::CRulerView()
{
	m_rulerType   = RT_HORIZONTAL;
	m_scrollPos   = 0;
	m_lastPos     = 0;
}

CRulerView::~CRulerView()
{
}


BEGIN_MESSAGE_MAP(CRulerView, CView)
	//{{AFX_MSG_MAP(CRulerView)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

void CRulerView::UpdateRulersInfo(stRULER_INFO stRulerInfo)
{
    m_DocSize     = stRulerInfo.DocSize;
    m_scrollPos   = stRulerInfo.ScrollPos;
  if (stRulerInfo.uMessage == RW_POSITION) 
	{
        DrawCursorPos(stRulerInfo.Pos);//重绘鼠标所在位置刻度
    }
    else if ((m_rulerType == RT_HORIZONTAL)&& (stRulerInfo.uMessage == RW_HSCROLL) ||
             (m_rulerType == RT_VERTICAL) && (stRulerInfo.uMessage == RW_VSCROLL))
	{
		Invalidate();//重绘刻度视图
    }
} 


void CRulerView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	m_lastPos = 0;
	int oldMapMode=pDC->SetMapMode(MM_TEXT);//设置映射方式（像素）
	CFont vFont;//垂直标尺字体
	CFont hFont;//水平标尺字体
	vFont.CreateFont(10, 0, 900, 900, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_TT_ALWAYS, PROOF_QUALITY, VARIABLE_PITCH|FF_ROMAN, "Times New Roman");
	hFont.CreateFont(12, 0, 000, 000, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_TT_ALWAYS, PROOF_QUALITY, VARIABLE_PITCH|FF_ROMAN, "Times New Roman");	
    CFont* pOldFont  = pDC->SelectObject((m_rulerType==RT_HORIZONTAL)?&hFont:&vFont);//载入字体
	int oldTextAlign = pDC->SetTextAlign((m_rulerType==RT_HORIZONTAL)?(TA_RIGHT|TA_TOP):(TA_LEFT|TA_TOP));//设置文字方向
	int oldBkMode    = pDC->SetBkMode(TRANSPARENT);//设置背景模式
	CRect rulerRect;
	GetClientRect(&rulerRect);//视图客户窗口作为标尺区域
	if (m_rulerType==RT_HORIZONTAL)//水平标尺
	{
		rulerRect.right = (int)m_DocSize.cx;//水平区域
    }
	else //(m_rulerType==RT_VERTICAL)
	{
		rulerRect.bottom = (int)m_DocSize.cy;//垂直区域
	}
	pDC->FillSolidRect(rulerRect, RGB(200, 200, 200));//填充背景
	DrawTicker(pDC, rulerRect, 100,TRUE);//绘制刻度线
    DrawTicker(pDC, rulerRect, 10, 10, FALSE);
    DrawTicker(pDC, rulerRect, 5, 12, FALSE);
	// 恢复DC为原来默认的设置
	pDC->SetMapMode(oldMapMode);
    pDC->SelectObject(pOldFont);
	pDC->SetTextAlign(oldTextAlign);
	pDC->SetBkMode(oldBkMode);
}

void CRulerView::DrawTicker( CDC* pDC,CRect rulerRect, int nFactor, int nBegin, bool bShowPos,bool thick_flag)
{
    int nSize  = (m_rulerType == RT_HORIZONTAL)?(int)(rulerRect.right/nFactor):(int)(rulerRect.bottom/nFactor);//刻度数目
    int nTick  = (int)(nFactor);//刻度间距
    for (int i=1; i<nSize; i++)
	{
		char buffer[100];
		CString num_h;
		num_h.Format("%d", i*nFactor);//刻度标识
		sprintf(buffer, "%d", i*nFactor);
		if (m_rulerType==RT_HORIZONTAL)//水平标尺
			{
			if(nTick*i-m_scrollPos.x>=0&&nTick*i-m_scrollPos.x<=1024)
				{
					pDC->PatBlt(nTick*i-m_scrollPos.x, rulerRect.top+nBegin, 1, rulerRect.bottom, BLACKNESS);//绘制刻度线
					if (bShowPos)//刻度标识
					pDC->TextOut(nTick*i-m_scrollPos.x, rulerRect.top, num_h);//显示文字
				}
			}
		else //(m_rulerType==RT_VERTICAL)
			{
				if(nTick*i-m_scrollPos.y<=768&&nTick*i-m_scrollPos.y>=0)
				{
				 pDC->PatBlt(rulerRect.left+nBegin, nTick*i-m_scrollPos.y, rulerRect.right, 1, BLACKNESS);//绘制刻度线
				if (bShowPos)//刻度标识
				 pDC->TextOut(rulerRect.left, nTick*i-m_scrollPos.y, CString(buffer));//显示文字
				}
			}
	}
}

void CRulerView::DrawCursorPos(CPoint NewPos)
{
	if (((m_rulerType == RT_HORIZONTAL) && (NewPos.x > m_DocSize.cx)) ||
		((m_rulerType == RT_VERTICAL) && ((NewPos.y) > m_DocSize.cy)))
		return;
	CDC* pDC = GetDC();
	//设置映射模式（像素）
	int oldMapMode = pDC->SetMapMode(MM_TEXT);
	CRect clientRect;
	GetClientRect(&clientRect);
	if (m_rulerType==RT_HORIZONTAL)//水平标尺
	{
		//将以前的鼠标位置标识删除
        pDC->PatBlt(m_lastPos.x, clientRect.top, 1, clientRect.bottom, DSTINVERT);
		//在新的位置绘制鼠标位置标识
		m_lastPos.x = NewPos.x;
        pDC->PatBlt(m_lastPos.x, clientRect.top, 1, clientRect.bottom, DSTINVERT);
	}
	else // (m_rulerType==RT_VERTICAL)
	{
		//将以前的鼠标位置标识删除
        pDC->PatBlt(clientRect.left, m_lastPos.y, clientRect.right, 1, DSTINVERT);
		//在新的位置绘制鼠标位置标识
		m_lastPos.y = NewPos.y;
        pDC->PatBlt(clientRect.left, m_lastPos.y, clientRect.right, 1, DSTINVERT);
	}
	pDC->SetMapMode(oldMapMode);//恢复默认的DC设置
	ReleaseDC(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CRulerView diagnostics

#ifdef _DEBUG
void CRulerView::AssertValid() const
{
	CView::AssertValid();
}

void CRulerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRulerView message handlers

void CRulerView::OnMouseMove(UINT nFlags, CPoint point) 
{
	//Invalidate();	
	CView::OnMouseMove(nFlags, point);
}
