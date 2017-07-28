// GetCurTime.h : main header file for the GETCURTIME application
//

#if !defined(AFX_GETCURTIME_H__92B0E969_E20A_4BDB_8B9F_470A449548B5__INCLUDED_)
#define AFX_GETCURTIME_H__92B0E969_E20A_4BDB_8B9F_470A449548B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetCurTimeApp:
// See GetCurTime.cpp for the implementation of this class
//

class CGetCurTimeApp : public CWinApp
{
public:
	CGetCurTimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetCurTimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetCurTimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETCURTIME_H__92B0E969_E20A_4BDB_8B9F_470A449548B5__INCLUDED_)
