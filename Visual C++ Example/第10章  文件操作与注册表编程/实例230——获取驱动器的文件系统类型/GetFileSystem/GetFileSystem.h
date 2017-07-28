// GetFileSystem.h : main header file for the GetFileSystem application
//

#if !defined(AFX_GetFileSystem_H__40AE9467_1071_4D9F_8097_A2254431EB2D__INCLUDED_)
#define AFX_GetFileSystem_H__40AE9467_1071_4D9F_8097_A2254431EB2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetFileSystemApp:
// See GetFileSystem.cpp for the implementation of this class
//

class CGetFileSystemApp : public CWinApp
{
public:
	CGetFileSystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetFileSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetFileSystemApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GetFileSystem_H__40AE9467_1071_4D9F_8097_A2254431EB2D__INCLUDED_)
