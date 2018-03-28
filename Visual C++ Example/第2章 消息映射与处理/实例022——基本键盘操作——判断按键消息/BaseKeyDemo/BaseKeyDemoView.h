// BaseKeyDemoView.h : interface of the CBaseKeyDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEKEYDEMOVIEW_H__9CD0938C_FC5B_4211_8F87_4D53B993705A__INCLUDED_)
#define AFX_BASEKEYDEMOVIEW_H__9CD0938C_FC5B_4211_8F87_4D53B993705A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseKeyDemoView : public CView
{
protected: // create from serialization only
	CBaseKeyDemoView();
	DECLARE_DYNCREATE(CBaseKeyDemoView)

// Attributes
public:
	CBaseKeyDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseKeyDemoView)
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
	virtual ~CBaseKeyDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL bShiftdown,bShiftup,bShiftB;

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseKeyDemoView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BaseKeyDemoView.cpp
inline CBaseKeyDemoDoc* CBaseKeyDemoView::GetDocument()
   { return (CBaseKeyDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEKEYDEMOVIEW_H__9CD0938C_FC5B_4211_8F87_4D53B993705A__INCLUDED_)
