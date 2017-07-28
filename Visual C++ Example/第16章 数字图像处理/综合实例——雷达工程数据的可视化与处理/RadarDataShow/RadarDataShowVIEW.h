// RadarDataShowView.h : interface of the CRadarDataShowView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RadarDataShowVIEW_H__0097DA73_8658_4C4D_A55E_6EEB68FCCC56__INCLUDED_)
#define AFX_RadarDataShowVIEW_H__0097DA73_8658_4C4D_A55E_6EEB68FCCC56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CChildFrame;

class CRadarDataShowView : public CScrollView
{
protected: // create from serialization only
	CRadarDataShowView();
	DECLARE_DYNCREATE(CRadarDataShowView)
	void  UpdateRulersInfo(int nMessage, CPoint ScrollPos, CPoint Pos = CPoint(0, 0)); 

// Attributes
public:
	CRadarDataShowDoc* GetDocument();

// Operations
public:
	int Show_Style;
	CPoint Dst;//BMP显示区域左、右上角横坐标
	CPoint dDst;//BMP显示宽度、高度
    CPoint Mouse_Move;//获取鼠标移动的纵、横坐标
	int Mouse_X;//获取鼠标点击的坐标
    CPoint Client_wh;//获取窗口高、宽
	int strollx;
	unsigned char *lpBufPtr_bmp;
	CChildFrame*  m_pParent;
	CSize    m_ImageSize;
	CPoint   m_RefScroll;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRadarDataShowView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRadarDataShowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRadarDataShowView)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnShowgray();
	afx_msg void OnUpdateShowgray(CCmdUI* pCmdUI);
	afx_msg void OnShowcolor();
	afx_msg void OnUpdateShowcolor(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnUpdateeIndicatorYY(CCmdUI* pCmdUI);
	afx_msg void OnUpdateeIndicatorXX(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RadarDataShowView.cpp
inline CRadarDataShowDoc* CRadarDataShowView::GetDocument()
   { return (CRadarDataShowDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RadarDataShowVIEW_H__0097DA73_8658_4C4D_A55E_6EEB68FCCC56__INCLUDED_)
