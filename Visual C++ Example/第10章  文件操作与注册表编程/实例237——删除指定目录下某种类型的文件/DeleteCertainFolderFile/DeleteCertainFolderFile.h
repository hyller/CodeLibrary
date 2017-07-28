// DeleteCertainFolderFile.h : main header file for the DELETECERTAINFOLDERFILE application
//

#if !defined(AFX_DELETECERTAINFOLDERFILE_H__E352D40A_602B_47EB_89E1_96508719ECD4__INCLUDED_)
#define AFX_DELETECERTAINFOLDERFILE_H__E352D40A_602B_47EB_89E1_96508719ECD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDeleteCertainFolderFileApp:
// See DeleteCertainFolderFile.cpp for the implementation of this class
//

class CDeleteCertainFolderFileApp : public CWinApp
{
public:
	CDeleteCertainFolderFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteCertainFolderFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDeleteCertainFolderFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETECERTAINFOLDERFILE_H__E352D40A_602B_47EB_89E1_96508719ECD4__INCLUDED_)
