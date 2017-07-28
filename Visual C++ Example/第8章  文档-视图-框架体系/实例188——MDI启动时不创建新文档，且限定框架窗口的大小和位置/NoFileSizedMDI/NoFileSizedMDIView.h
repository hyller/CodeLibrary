// NoFileSizedMDIView.h : interface of the CNoFileSizedMDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOFILESIZEDMDIVIEW_H__5FF98DF8_E657_4798_A99F_D2F80D1F4078__INCLUDED_)
#define AFX_NOFILESIZEDMDIVIEW_H__5FF98DF8_E657_4798_A99F_D2F80D1F4078__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNoFileSizedMDIView : public CView
{
protected: // create from serialization only
	CNoFileSizedMDIView();
	DECLARE_DYNCREATE(CNoFileSizedMDIView)

// Attributes
public:
	CNoFileSizedMDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoFileSizedMDIView)
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
	virtual ~CNoFileSizedMDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNoFileSizedMDIView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NoFileSizedMDIView.cpp
inline CNoFileSizedMDIDoc* CNoFileSizedMDIView::GetDocument()
   { return (CNoFileSizedMDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOFILESIZEDMDIVIEW_H__5FF98DF8_E657_4798_A99F_D2F80D1F4078__INCLUDED_)
