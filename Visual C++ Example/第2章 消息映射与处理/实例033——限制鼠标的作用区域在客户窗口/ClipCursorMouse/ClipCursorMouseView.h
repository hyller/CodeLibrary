// ClipCursorMouseView.h : interface of the CClipCursorMouseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIPCURSORMOUSEVIEW_H__66FE39FD_F1B3_4494_B163_192498F47949__INCLUDED_)
#define AFX_CLIPCURSORMOUSEVIEW_H__66FE39FD_F1B3_4494_B163_192498F47949__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CClipCursorMouseView : public CView
{
protected: // create from serialization only
	CClipCursorMouseView();
	DECLARE_DYNCREATE(CClipCursorMouseView)

// Attributes
public:
	CClipCursorMouseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipCursorMouseView)
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
	virtual ~CClipCursorMouseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CRect	oldrect;
// Generated message map functions
protected:
	//{{AFX_MSG(CClipCursorMouseView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ClipCursorMouseView.cpp
inline CClipCursorMouseDoc* CClipCursorMouseView::GetDocument()
   { return (CClipCursorMouseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPCURSORMOUSEVIEW_H__66FE39FD_F1B3_4494_B163_192498F47949__INCLUDED_)
