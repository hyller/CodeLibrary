// CopyBmpDemoView.h : interface of the CCopyBmpDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COPYBMPDEMOVIEW_H__A4CF5601_26B2_4173_BE3A_F17063396E11__INCLUDED_)
#define AFX_COPYBMPDEMOVIEW_H__A4CF5601_26B2_4173_BE3A_F17063396E11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCopyBmpDemoView : public CView
{
protected: // create from serialization only
	CCopyBmpDemoView();
	DECLARE_DYNCREATE(CCopyBmpDemoView)

// Attributes
public:
	CCopyBmpDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCopyBmpDemoView)
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
	virtual ~CCopyBmpDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CBitmap bmp;
// Generated message map functions
protected:
	//{{AFX_MSG(CCopyBmpDemoView)
	afx_msg void OnMenucopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CopyBmpDemoView.cpp
inline CCopyBmpDemoDoc* CCopyBmpDemoView::GetDocument()
   { return (CCopyBmpDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COPYBMPDEMOVIEW_H__A4CF5601_26B2_4173_BE3A_F17063396E11__INCLUDED_)
