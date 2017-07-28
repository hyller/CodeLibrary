// CursorMouseDemoView.h : interface of the CCursorMouseDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CURSORMOUSEDEMOVIEW_H__50DCB207_4ECF_4878_A3A4_4DDB265DBAD9__INCLUDED_)
#define AFX_CURSORMOUSEDEMOVIEW_H__50DCB207_4ECF_4878_A3A4_4DDB265DBAD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCursorMouseDemoView : public CView
{
protected: // create from serialization only
	CCursorMouseDemoView();
	DECLARE_DYNCREATE(CCursorMouseDemoView)

// Attributes
public:
	CCursorMouseDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCursorMouseDemoView)
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
	virtual ~CCursorMouseDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCursorMouseDemoView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CursorMouseDemoView.cpp
inline CCursorMouseDemoDoc* CCursorMouseDemoView::GetDocument()
   { return (CCursorMouseDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURSORMOUSEDEMOVIEW_H__50DCB207_4ECF_4878_A3A4_4DDB265DBAD9__INCLUDED_)
