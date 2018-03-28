// EnalbeMenuItemView.h : interface of the CEnalbeMenuItemView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EnalbeMenuItemVIEW_H__C08A6BA1_B00B_4575_9CAD_A4B2E9948CE3__INCLUDED_)
#define AFX_EnalbeMenuItemVIEW_H__C08A6BA1_B00B_4575_9CAD_A4B2E9948CE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEnalbeMenuItemView : public CView
{
protected: // create from serialization only
	CEnalbeMenuItemView();
	DECLARE_DYNCREATE(CEnalbeMenuItemView)

// Attributes
public:
	CEnalbeMenuItemDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnalbeMenuItemView)
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
	virtual ~CEnalbeMenuItemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL m_bvisible;

// Generated message map functions
protected:
	//{{AFX_MSG(CEnalbeMenuItemView)
	afx_msg void OnMenurun();
	afx_msg void OnMenupause();
	afx_msg void OnUpdateMenupause(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMenurun(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EnalbeMenuItemView.cpp
inline CEnalbeMenuItemDoc* CEnalbeMenuItemView::GetDocument()
   { return (CEnalbeMenuItemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EnalbeMenuItemVIEW_H__C08A6BA1_B00B_4575_9CAD_A4B2E9948CE3__INCLUDED_)
