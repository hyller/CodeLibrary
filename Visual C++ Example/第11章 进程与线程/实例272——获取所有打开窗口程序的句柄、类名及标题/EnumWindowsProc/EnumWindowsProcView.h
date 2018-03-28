// EnumWindowsProcView.h : interface of the CEnumWindowsProcView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENUMWINDOWSPROCVIEW_H__B733D1CF_8BD6_430D_BD2F_70C6E1058D9E__INCLUDED_)
#define AFX_ENUMWINDOWSPROCVIEW_H__B733D1CF_8BD6_430D_BD2F_70C6E1058D9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEnumWindowsProcView : public CListView
{
protected: // create from serialization only
	CEnumWindowsProcView();
	DECLARE_DYNCREATE(CEnumWindowsProcView)

// Attributes
public:
	CEnumWindowsProcDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumWindowsProcView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEnumWindowsProcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	static BOOL CALLBACK MyEnumWindowsProc(HWND hwnd, LPARAM lParam);
	//{{AFX_MSG(CEnumWindowsProcView)
	afx_msg void OnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EnumWindowsProcView.cpp
inline CEnumWindowsProcDoc* CEnumWindowsProcView::GetDocument()
   { return (CEnumWindowsProcDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMWINDOWSPROCVIEW_H__B733D1CF_8BD6_430D_BD2F_70C6E1058D9E__INCLUDED_)
