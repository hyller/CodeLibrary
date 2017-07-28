// GetHttpFile.h : main header file for the GetHttpFile application
//

#if !defined(AFX_GetHttpFile_H__92B603EE_EB94_41A0_B975_92C2B88CB17B__INCLUDED_)
#define AFX_GetHttpFile_H__92B603EE_EB94_41A0_B975_92C2B88CB17B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetHttpFileApp:
// See GetHttpFile.cpp for the implementation of this class
//

class CGetHttpFileApp : public CWinApp
{
public:
	CGetHttpFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetHttpFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetHttpFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GetHttpFile_H__92B603EE_EB94_41A0_B975_92C2B88CB17B__INCLUDED_)
