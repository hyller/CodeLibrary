// GetFolderTime.h : main header file for the GETFOLDERTIME application
//

#if !defined(AFX_GETFOLDERTIME_H__276064C6_8BE2_4EB0_BA6A_73E430A80175__INCLUDED_)
#define AFX_GETFOLDERTIME_H__276064C6_8BE2_4EB0_BA6A_73E430A80175__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetFolderTimeApp:
// See GetFolderTime.cpp for the implementation of this class
//

class CGetFolderTimeApp : public CWinApp
{
public:
	CGetFolderTimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetFolderTimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetFolderTimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETFOLDERTIME_H__276064C6_8BE2_4EB0_BA6A_73E430A80175__INCLUDED_)
