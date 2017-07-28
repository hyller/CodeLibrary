#if !defined(AFX_LEFTFORMVIEW_H__20240468_9460_44DE_B223_1F6E1812CFBC__INCLUDED_)
#define AFX_LEFTFORMVIEW_H__20240468_9460_44DE_B223_1F6E1812CFBC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftFormView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftFormView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CLeftFormView : public CFormView
{
protected:
	CLeftFormView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftFormView)

// Form Data
public:
	//{{AFX_DATA(CLeftFormView)
	enum { IDD = IDD_DIALOG1 };
	CString	m_Number;
	CString	m_Name;
	CString	m_Magor;
	CString	m_Home;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftFormView)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnDraw(CDC* pDC);

	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLeftFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLeftFormView)
	afx_msg void OnCheckin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTFORMVIEW_H__20240468_9460_44DE_B223_1F6E1812CFBC__INCLUDED_)
