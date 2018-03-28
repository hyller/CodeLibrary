// ODBCDatabase2.h : main header file for the ODBCDatabase2 application
//

#if !defined(AFX_ODBCDatabase2_H__036085C5_9718_4868_B973_9BE63749F6F5__INCLUDED_)
#define AFX_ODBCDatabase2_H__036085C5_9718_4868_B973_9BE63749F6F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2App:
// See ODBCDatabase2.cpp for the implementation of this class
//

class CODBCDatabase2App : public CWinApp
{
public:
	CODBCDatabase2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDatabase2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CODBCDatabase2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDatabase2_H__036085C5_9718_4868_B973_9BE63749F6F5__INCLUDED_)
