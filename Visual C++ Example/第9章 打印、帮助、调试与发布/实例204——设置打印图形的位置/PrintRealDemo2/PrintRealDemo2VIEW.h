// PrintRealDemo2View.h : interface of the CPrintRealDemo2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PrintRealDemo2VIEW_H__C544FA8A_0706_4CDF_9DC3_412E5FE3BF95__INCLUDED_)
#define AFX_PrintRealDemo2VIEW_H__C544FA8A_0706_4CDF_9DC3_412E5FE3BF95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPrintRealDemo2View : public CView
{
protected: // create from serialization only
	CPrintRealDemo2View();
	DECLARE_DYNCREATE(CPrintRealDemo2View)

// Attributes
public:
	CPrintRealDemo2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintRealDemo2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintRealDemo2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPrintRealDemo2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PrintRealDemo2View.cpp
inline CPrintRealDemo2Doc* CPrintRealDemo2View::GetDocument()
   { return (CPrintRealDemo2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PrintRealDemo2VIEW_H__C544FA8A_0706_4CDF_9DC3_412E5FE3BF95__INCLUDED_)
