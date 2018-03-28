// PaintDcDemoView.h : interface of the CPaintDcDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAINTDCDEMOVIEW_H__E5DD2933_8B59_442B_BE53_7EEDF06A75BB__INCLUDED_)
#define AFX_PAINTDCDEMOVIEW_H__E5DD2933_8B59_442B_BE53_7EEDF06A75BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPaintDcDemoView : public CView
{
protected: // create from serialization only
	CPaintDcDemoView();
	DECLARE_DYNCREATE(CPaintDcDemoView)

// Attributes
public:
	CPaintDcDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintDcDemoView)
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
	virtual ~CPaintDcDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPaintDcDemoView)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PaintDcDemoView.cpp
inline CPaintDcDemoDoc* CPaintDcDemoView::GetDocument()
   { return (CPaintDcDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTDCDEMOVIEW_H__E5DD2933_8B59_442B_BE53_7EEDF06A75BB__INCLUDED_)
