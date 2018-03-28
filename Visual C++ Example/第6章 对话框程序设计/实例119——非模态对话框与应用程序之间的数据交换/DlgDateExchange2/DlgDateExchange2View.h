// DlgDateExchange2View.h : interface of the CDlgDateExchange2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DlgDateExchange2VIEW_H__D94705B1_8F05_4134_9E2A_DC7FB9F1A594__INCLUDED_)
#define AFX_DlgDateExchange2VIEW_H__D94705B1_8F05_4134_9E2A_DC7FB9F1A594__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TextColorDlg.h"

class CDlgDateExchange2View : public CView
{
protected: // create from serialization only
	CDlgDateExchange2View();
	DECLARE_DYNCREATE(CDlgDateExchange2View)

// Attributes
public:
	CDlgDateExchange2Doc* GetDocument();
	CTextColorDlg* pDialog;		//对话框类对象指针 
// Operations
public:
	int r,g,b;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDateExchange2View)
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
	virtual ~CDlgDateExchange2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// Generated message map functions
protected:
	//{{AFX_MSG(CDlgDateExchange2View)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetColor(WPARAM wP,LPARAM lP); 
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DlgDateExchange2View.cpp
inline CDlgDateExchange2Doc* CDlgDateExchange2View::GetDocument()
   { return (CDlgDateExchange2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgDateExchange2VIEW_H__D94705B1_8F05_4134_9E2A_DC7FB9F1A594__INCLUDED_)
