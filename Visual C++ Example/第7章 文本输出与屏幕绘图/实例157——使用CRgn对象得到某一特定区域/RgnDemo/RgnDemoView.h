// RgnDemoView.h : interface of the CRgnDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGNDEMOVIEW_H__496E179E_7436_43F0_BB05_76D131413428__INCLUDED_)
#define AFX_RGNDEMOVIEW_H__496E179E_7436_43F0_BB05_76D131413428__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRgnDemoView : public CView
{
protected: // create from serialization only
	CRgnDemoView();
	DECLARE_DYNCREATE(CRgnDemoView)

// Attributes
public:
	CRgnDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRgnDemoView)
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
	virtual ~CRgnDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CRgn rgnA,rgnB;//声明两个区域对象
	CString str;

// Generated message map functions
protected:
	//{{AFX_MSG(CRgnDemoView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RgnDemoView.cpp
inline CRgnDemoDoc* CRgnDemoView::GetDocument()
   { return (CRgnDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGNDEMOVIEW_H__496E179E_7436_43F0_BB05_76D131413428__INCLUDED_)
