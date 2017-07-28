// SheetDlgDemo.h : main header file for the SheetDlgDemo application
//

#if !defined(AFX_SheetDlgDemo_H__292287D5_EA1E_4320_9301_82E8F5535AFC__INCLUDED_)
#define AFX_SheetDlgDemo_H__292287D5_EA1E_4320_9301_82E8F5535AFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSheetDlgDemoApp:
// See SheetDlgDemo.cpp for the implementation of this class
//

class CSheetDlgDemoApp : public CWinApp
{
public:
	CSheetDlgDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSheetDlgDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSheetDlgDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SheetDlgDemo_H__292287D5_EA1E_4320_9301_82E8F5535AFC__INCLUDED_)
