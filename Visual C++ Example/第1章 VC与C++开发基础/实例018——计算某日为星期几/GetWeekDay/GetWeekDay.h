// GetWeekDay.h : main header file for the GETWEEKDAY application
//

#if !defined(AFX_GETWEEKDAY_H__AE6AA2C9_7790_47AC_9459_B150708BBB8E__INCLUDED_)
#define AFX_GETWEEKDAY_H__AE6AA2C9_7790_47AC_9459_B150708BBB8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetWeekDayApp:
// See GetWeekDay.cpp for the implementation of this class
//

class CGetWeekDayApp : public CWinApp
{
public:
	CGetWeekDayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetWeekDayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetWeekDayApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETWEEKDAY_H__AE6AA2C9_7790_47AC_9459_B150708BBB8E__INCLUDED_)
