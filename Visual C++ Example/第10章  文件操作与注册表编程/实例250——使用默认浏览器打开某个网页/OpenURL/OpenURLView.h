// OpenURLView.h : interface of the COpenURLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENURLVIEW_H__2902772D_1810_48FD_A360_A7F4EBAE4809__INCLUDED_)
#define AFX_OPENURLVIEW_H__2902772D_1810_48FD_A360_A7F4EBAE4809__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COpenURLView : public CView
{
protected: // create from serialization only
	COpenURLView();
	DECLARE_DYNCREATE(COpenURLView)

// Attributes
public:
	COpenURLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenURLView)
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
	virtual ~COpenURLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenURLView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OpenURLView.cpp
inline COpenURLDoc* COpenURLView::GetDocument()
   { return (COpenURLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENURLVIEW_H__2902772D_1810_48FD_A360_A7F4EBAE4809__INCLUDED_)
