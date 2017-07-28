#if !defined(AFX_MYPROPERTYSHEET_H__915C679B_F5F0_4231_9A13_F27BE15022C6__INCLUDED_)
#define AFX_MYPROPERTYSHEET_H__915C679B_F5F0_4231_9A13_F27BE15022C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyPropertySheet.h : header file
//
#include "ShapePage.h"
#include "ColorPage.h"
/////////////////////////////////////////////////////////////////////////////
// CMyPropertySheet

class CMyPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CMyPropertySheet)

// Construction
public:
	CMyPropertySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CShapePage pageFirst; //图形属性页对象
	CColorPage pageSecond; //画刷色设置属性页对象
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyPropertySheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyPropertySheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyPropertySheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYPROPERTYSHEET_H__915C679B_F5F0_4231_9A13_F27BE15022C6__INCLUDED_)
