// StaticSplitWndView.h : interface of the CStaticSplitWndView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_StaticSplitWndVIEW_H__A27EEC81_5A32_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_StaticSplitWndVIEW_H__A27EEC81_5A32_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStaticSplitWndView : public CView
{
protected: // create from serialization only
	CStaticSplitWndView();
	DECLARE_DYNCREATE(CStaticSplitWndView)

// Attributes
public:
//	CStaticSplitWndDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticSplitWndView)
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
	virtual ~CStaticSplitWndView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStaticSplitWndView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StaticSplitWndView.cpp
inline CStaticSplitWndDoc* CStaticSplitWndView::GetDocument()
   { return (CStaticSplitWndDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_StaticSplitWndVIEW_H__A27EEC81_5A32_11D6_8F32_00E04CE76240__INCLUDED_)
