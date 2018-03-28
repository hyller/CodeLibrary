// MultiViewDemoView.h : interface of the CMultiViewDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIVIEWDEMOVIEW_H__979C5AE1_B0B6_4F9B_8291_9C9C63B2C632__INCLUDED_)
#define AFX_MULTIVIEWDEMOVIEW_H__979C5AE1_B0B6_4F9B_8291_9C9C63B2C632__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MultiViewDemoDoc.h"

class CMultiViewDemoView : public CView
{
protected: // create from serialization only
	CMultiViewDemoView();
	DECLARE_DYNCREATE(CMultiViewDemoView)
	CSplitterWnd    m_wndSplitter2;//用于产生第二次静态切分

// Attributes
public:
	CMultiViewDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiViewDemoView)
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
	virtual ~CMultiViewDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiViewDemoView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MultiViewDemoView.cpp
inline CMultiViewDemoDoc* CMultiViewDemoView::GetDocument()
   { return (CMultiViewDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIVIEWDEMOVIEW_H__979C5AE1_B0B6_4F9B_8291_9C9C63B2C632__INCLUDED_)
