// RegistDemoView.h : interface of the CRegistDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGISTDEMOVIEW_H__FECC29D4_D433_4A09_80C1_14A76A769788__INCLUDED_)
#define AFX_REGISTDEMOVIEW_H__FECC29D4_D433_4A09_80C1_14A76A769788__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRegistDemoView : public CView
{
protected: // create from serialization only
	CRegistDemoView();
	DECLARE_DYNCREATE(CRegistDemoView)

// Attributes
public:
	CRegistDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegistDemoView)
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
	virtual ~CRegistDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRegistDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RegistDemoView.cpp
inline CRegistDemoDoc* CRegistDemoView::GetDocument()
   { return (CRegistDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTDEMOVIEW_H__FECC29D4_D433_4A09_80C1_14A76A769788__INCLUDED_)
