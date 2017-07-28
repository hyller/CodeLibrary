// DrawArrowDemoView.h : interface of the CDrawArrowDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWARROWDEMOVIEW_H__8ACEF44B_361E_481B_972E_295C548C1348__INCLUDED_)
#define AFX_DRAWARROWDEMOVIEW_H__8ACEF44B_361E_481B_972E_295C548C1348__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawArrowDemoView : public CView
{
protected: // create from serialization only
	CDrawArrowDemoView();
	DECLARE_DYNCREATE(CDrawArrowDemoView)
	void DrawArrow(CPoint p1,CPoint p2,double theta,int length);
// Attributes
public:
	CDrawArrowDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawArrowDemoView)
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
	virtual ~CDrawArrowDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawArrowDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrawArrowDemoView.cpp
inline CDrawArrowDemoDoc* CDrawArrowDemoView::GetDocument()
   { return (CDrawArrowDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWARROWDEMOVIEW_H__8ACEF44B_361E_481B_972E_295C548C1348__INCLUDED_)
