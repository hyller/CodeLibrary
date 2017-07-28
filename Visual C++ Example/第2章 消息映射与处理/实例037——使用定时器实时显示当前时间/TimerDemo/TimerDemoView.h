// TimerDemoView.h : interface of the CTimerDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMERDEMOVIEW_H__29D8D872_07A7_4C10_B933_DEF40C889D43__INCLUDED_)
#define AFX_TIMERDEMOVIEW_H__29D8D872_07A7_4C10_B933_DEF40C889D43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTimerDemoView : public CView
{
protected: // create from serialization only
	CTimerDemoView();
	DECLARE_DYNCREATE(CTimerDemoView)

// Attributes
public:
	CTimerDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimerDemoView)
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
	virtual ~CTimerDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTimerDemoView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TimerDemoView.cpp
inline CTimerDemoDoc* CTimerDemoView::GetDocument()
   { return (CTimerDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERDEMOVIEW_H__29D8D872_07A7_4C10_B933_DEF40C889D43__INCLUDED_)
