// AniBitmapWndView.h : interface of the CAniBitmapWndView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANIBITMAPWNDVIEW_H__B6E0233A_88A1_4FDE_AA72_BAE5F60D2144__INCLUDED_)
#define AFX_ANIBITMAPWNDVIEW_H__B6E0233A_88A1_4FDE_AA72_BAE5F60D2144__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAniBitmapWndView : public CView
{
protected: // create from serialization only
	CAniBitmapWndView();
	DECLARE_DYNCREATE(CAniBitmapWndView)

// Attributes
public:
	CAniBitmapWndDoc* GetDocument();

// Operations
public:
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAniBitmapWndView)
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
	virtual ~CAniBitmapWndView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
		CBrush m_brushBackground;

// Generated message map functions
protected:
	//{{AFX_MSG(CAniBitmapWndView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AniBitmapWndView.cpp
inline CAniBitmapWndDoc* CAniBitmapWndView::GetDocument()
   { return (CAniBitmapWndDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIBITMAPWNDVIEW_H__B6E0233A_88A1_4FDE_AA72_BAE5F60D2144__INCLUDED_)
