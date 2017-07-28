// BmpZoomPartView.h : interface of the CBmpZoomPartView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BMPZOOMPARTVIEW_H__32F28A47_91C1_4F6F_A0C2_A52B91152C64__INCLUDED_)
#define AFX_BMPZOOMPARTVIEW_H__32F28A47_91C1_4F6F_A0C2_A52B91152C64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBmpZoomPartView : public CView
{
protected: // create from serialization only
	CBmpZoomPartView();
	DECLARE_DYNCREATE(CBmpZoomPartView)

// Attributes
public:
	CBmpZoomPartDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpZoomPartView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBmpZoomPartView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:			
	CSize m_sizeSource;//源位图的尺寸
	CBitmap * m_pBitmap;//位图对象
	CDC * m_pdcMem;//兼容内存DC
	bool bFirstload,bFistLdown;
	int oldx,oldy,s,d;//目标和缩放后正方形区域大小
// Generated message map functions
protected:
	//{{AFX_MSG(CBmpZoomPartView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BmpZoomPartView.cpp
inline CBmpZoomPartDoc* CBmpZoomPartView::GetDocument()
   { return (CBmpZoomPartDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPZOOMPARTVIEW_H__32F28A47_91C1_4F6F_A0C2_A52B91152C64__INCLUDED_)
