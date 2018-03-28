#if !defined(AFX_MYHTMLCTRL_H__BAC003B5_FE05_4392_A120_29389D5F5514__INCLUDED_)
#define AFX_MYHTMLCTRL_H__BAC003B5_FE05_4392_A120_29389D5F5514__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyHtmlCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyHtmlCtrl html view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include <afxhtml.h>

class CMyHtmlCtrl : public CHtmlView
{
public:
	CMyHtmlCtrl();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyHtmlCtrl)
	BOOL CreateFromStatic(UINT nID, CWnd* pParent);
	virtual void PostNcDestroy();
// html Data
public:
	//{{AFX_DATA(CMyHtmlCtrl)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyHtmlCtrl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyHtmlCtrl();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMyHtmlCtrl)
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYHTMLCTRL_H__BAC003B5_FE05_4392_A120_29389D5F5514__INCLUDED_)
