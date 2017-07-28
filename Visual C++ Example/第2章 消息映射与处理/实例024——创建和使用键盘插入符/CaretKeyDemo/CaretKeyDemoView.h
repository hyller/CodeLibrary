// CaretKeyDemoView.h : interface of the CCaretKeyDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARETKEYDEMOVIEW_H__23CEF80C_C22A_4B65_8F24_9DEDE42BBA93__INCLUDED_)
#define AFX_CARETKEYDEMOVIEW_H__23CEF80C_C22A_4B65_8F24_9DEDE42BBA93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCaretKeyDemoView : public CView
{
protected: // create from serialization only
	CCaretKeyDemoView();
	DECLARE_DYNCREATE(CCaretKeyDemoView)

// Attributes
public:
	CCaretKeyDemoDoc* GetDocument();

// Operations
public:
	CPoint ptCharacter;								//¼ÇÂ¼×Ö·ûÎ»ÖÃ
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaretKeyDemoView)
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
	virtual ~CCaretKeyDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCaretKeyDemoView)
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CaretKeyDemoView.cpp
inline CCaretKeyDemoDoc* CCaretKeyDemoView::GetDocument()
   { return (CCaretKeyDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARETKEYDEMOVIEW_H__23CEF80C_C22A_4B65_8F24_9DEDE42BBA93__INCLUDED_)
