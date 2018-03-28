// CircleWaveView.h : interface of the CCircleWaveView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLEWAVEVIEW_H__74A0F28E_BEA6_4611_91F6_3AB31C2CD3DA__INCLUDED_)
#define AFX_CIRCLEWAVEVIEW_H__74A0F28E_BEA6_4611_91F6_3AB31C2CD3DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define RED 1
#define GREEN 2
#define BLUE 3
#define CYAN  4
#define MAGENTA 5
#define GRAY 6
#define PI 3.1415926

class CCircleWaveView : public CView
{
protected: // create from serialization only
	CCircleWaveView();
	DECLARE_DYNCREATE(CCircleWaveView)
	CPoint center;//圆心
	CRect rect;//客户窗口大小
	COLORREF rgb[6];//颜色数组
	int icolor;
// Attributes
public:
	CCircleWaveDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleWaveView)
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
	virtual ~CCircleWaveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCircleWaveView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CircleWaveView.cpp
inline CCircleWaveDoc* CCircleWaveView::GetDocument()
   { return (CCircleWaveDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLEWAVEVIEW_H__74A0F28E_BEA6_4611_91F6_3AB31C2CD3DA__INCLUDED_)
