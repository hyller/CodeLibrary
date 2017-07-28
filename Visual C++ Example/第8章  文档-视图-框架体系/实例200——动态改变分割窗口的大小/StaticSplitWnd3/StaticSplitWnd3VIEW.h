// StaticSplitWnd3View.h : interface of the CStaticSplitWnd3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_StaticSplitWnd3VIEW_H__A27EEC81_5A32_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_StaticSplitWnd3VIEW_H__A27EEC81_5A32_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStaticSplitWnd3View : public CView
{
protected: // create from serialization only
	CStaticSplitWnd3View();
	DECLARE_DYNCREATE(CStaticSplitWnd3View)

// Attributes
public:
//	CStaticSplitWnd3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticSplitWnd3View)
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
	virtual ~CStaticSplitWnd3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStaticSplitWnd3View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StaticSplitWnd3View.cpp
inline CStaticSplitWnd3Doc* CStaticSplitWnd3View::GetDocument()
   { return (CStaticSplitWnd3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_StaticSplitWnd3VIEW_H__A27EEC81_5A32_11D6_8F32_00E04CE76240__INCLUDED_)
