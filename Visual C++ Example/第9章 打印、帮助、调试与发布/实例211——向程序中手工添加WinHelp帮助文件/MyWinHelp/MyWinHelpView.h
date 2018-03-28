// MyWinHelpView.h : interface of the CMyWinHelpView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYWINHELPVIEW_H__0426EEAB_9A92_471C_A91F_838FFD0F2F4E__INCLUDED_)
#define AFX_MYWINHELPVIEW_H__0426EEAB_9A92_471C_A91F_838FFD0F2F4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyWinHelpView : public CView
{
protected: // create from serialization only
	CMyWinHelpView();
	DECLARE_DYNCREATE(CMyWinHelpView)

// Attributes
public:
	CMyWinHelpDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWinHelpView)
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
	virtual ~CMyWinHelpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyWinHelpView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyWinHelpView.cpp
inline CMyWinHelpDoc* CMyWinHelpView::GetDocument()
   { return (CMyWinHelpDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWINHELPVIEW_H__0426EEAB_9A92_471C_A91F_838FFD0F2F4E__INCLUDED_)
