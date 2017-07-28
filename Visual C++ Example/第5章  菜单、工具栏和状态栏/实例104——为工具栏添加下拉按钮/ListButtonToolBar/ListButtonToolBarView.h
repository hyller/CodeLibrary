// ListButtonToolBarView.h : interface of the CListButtonToolBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTBUTTONTOOLBARVIEW_H__F698DAEE_7C6B_4335_BE85_176DE6B69940__INCLUDED_)
#define AFX_LISTBUTTONTOOLBARVIEW_H__F698DAEE_7C6B_4335_BE85_176DE6B69940__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CListButtonToolBarView : public CView
{
protected: // create from serialization only
	CListButtonToolBarView();
	DECLARE_DYNCREATE(CListButtonToolBarView)

// Attributes
public:
	CListButtonToolBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListButtonToolBarView)
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
	virtual ~CListButtonToolBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CListButtonToolBarView)
	afx_msg void OnMenuitem32775();
	afx_msg void OnMenuitem32777();
	afx_msg void OnMenuitem32778();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ListButtonToolBarView.cpp
inline CListButtonToolBarDoc* CListButtonToolBarView::GetDocument()
   { return (CListButtonToolBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBUTTONTOOLBARVIEW_H__F698DAEE_7C6B_4335_BE85_176DE6B69940__INCLUDED_)
