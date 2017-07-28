// WindowDcDemoView.h : interface of the CWindowDcDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOWDCDEMOVIEW_H__E490FA8A_8AFE_48F0_A3A2_6C136E7F729B__INCLUDED_)
#define AFX_WINDOWDCDEMOVIEW_H__E490FA8A_8AFE_48F0_A3A2_6C136E7F729B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWindowDcDemoView : public CView
{
protected: // create from serialization only
	CWindowDcDemoView();
	DECLARE_DYNCREATE(CWindowDcDemoView)

// Attributes
public:
	CWindowDcDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowDcDemoView)
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
	virtual ~CWindowDcDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWindowDcDemoView)
	afx_msg void OnPaint();
	afx_msg void OnFramedraw();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in WindowDcDemoView.cpp
inline CWindowDcDemoDoc* CWindowDcDemoView::GetDocument()
   { return (CWindowDcDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWDCDEMOVIEW_H__E490FA8A_8AFE_48F0_A3A2_6C136E7F729B__INCLUDED_)
