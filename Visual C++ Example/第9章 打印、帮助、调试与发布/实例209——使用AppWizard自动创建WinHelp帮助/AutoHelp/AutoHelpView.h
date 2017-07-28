// AutoHelpView.h : interface of the CAutoHelpView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTOHELPVIEW_H__1309C33D_2D76_4D26_958B_A93E80B5F3B7__INCLUDED_)
#define AFX_AUTOHELPVIEW_H__1309C33D_2D76_4D26_958B_A93E80B5F3B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAutoHelpView : public CView
{
protected: // create from serialization only
	CAutoHelpView();
	DECLARE_DYNCREATE(CAutoHelpView)

// Attributes
public:
	CAutoHelpDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoHelpView)
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
	virtual ~CAutoHelpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAutoHelpView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AutoHelpView.cpp
inline CAutoHelpDoc* CAutoHelpView::GetDocument()
   { return (CAutoHelpDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOHELPVIEW_H__1309C33D_2D76_4D26_958B_A93E80B5F3B7__INCLUDED_)
