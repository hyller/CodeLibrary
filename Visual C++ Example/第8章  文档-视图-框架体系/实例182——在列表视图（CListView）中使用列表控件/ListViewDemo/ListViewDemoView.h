// ListViewDemoView.h : interface of the CListViewDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTVIEWDEMOVIEW_H__B42386EE_D56D_4C41_A090_B4AAFAAE935C__INCLUDED_)
#define AFX_LISTVIEWDEMOVIEW_H__B42386EE_D56D_4C41_A090_B4AAFAAE935C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CListViewDemoView : public CListView
{
protected: // create from serialization only
	CListViewDemoView();
	DECLARE_DYNCREATE(CListViewDemoView)

// Attributes
public:
	CListViewDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListViewDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListViewDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CListViewDemoView)
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ListViewDemoView.cpp
inline CListViewDemoDoc* CListViewDemoView::GetDocument()
   { return (CListViewDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTVIEWDEMOVIEW_H__B42386EE_D56D_4C41_A090_B4AAFAAE935C__INCLUDED_)
