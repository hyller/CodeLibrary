// ZhuceDemoView.h : interface of the CZhuceDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZHUCEDEMOVIEW_H__FFC253A9_234E_4A44_B154_99B3B0042AF6__INCLUDED_)
#define AFX_ZHUCEDEMOVIEW_H__FFC253A9_234E_4A44_B154_99B3B0042AF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CZhuceDemoView : public CView
{
protected: // create from serialization only
	CZhuceDemoView();
	DECLARE_DYNCREATE(CZhuceDemoView)

// Attributes
public:
	CZhuceDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZhuceDemoView)
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
	virtual ~CZhuceDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CZhuceDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ZhuceDemoView.cpp
inline CZhuceDemoDoc* CZhuceDemoView::GetDocument()
   { return (CZhuceDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHUCEDEMOVIEW_H__FFC253A9_234E_4A44_B154_99B3B0042AF6__INCLUDED_)
