// PropertySheetDemo2View.h : interface of the CPropertySheetDemo2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PropertySheetDemo2VIEW_H__E553CEF2_18B7_4D50_981B_CAB8887D9DC0__INCLUDED_)
#define AFX_PropertySheetDemo2VIEW_H__E553CEF2_18B7_4D50_981B_CAB8887D9DC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyPropertySheet.h"

class CPropertySheetDemo2View : public CView
{
protected: // create from serialization only
	CPropertySheetDemo2View();
	DECLARE_DYNCREATE(CPropertySheetDemo2View)

// Attributes
public:
	CPropertySheetDemo2Doc* GetDocument();

// Operations
public:
	int m_r,m_g,m_b,m_type;
	CMyPropertySheet m_Sheet;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertySheetDemo2View)
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
	virtual ~CPropertySheetDemo2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPropertySheetDemo2View)
	afx_msg void OnMenuset();

	afx_msg void OnApply(WPARAM wParam, LPARAM lParam);//¶¨Òåº¯Êý
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PropertySheetDemo2View.cpp
inline CPropertySheetDemo2Doc* CPropertySheetDemo2View::GetDocument()
   { return (CPropertySheetDemo2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PropertySheetDemo2VIEW_H__E553CEF2_18B7_4D50_981B_CAB8887D9DC0__INCLUDED_)
