// ODBCDatabase1.h : main header file for the ODBCDatabase1 application
//

#if !defined(AFX_ODBCDatabase1_H__036085C5_9718_4868_B973_9BE63749F6F5__INCLUDED_)
#define AFX_ODBCDatabase1_H__036085C5_9718_4868_B973_9BE63749F6F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1App:
// See ODBCDatabase1.cpp for the implementation of this class
//

class CODBCDatabase1App : public CWinApp
{
public:
	CODBCDatabase1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDatabase1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CODBCDatabase1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDatabase1_H__036085C5_9718_4868_B973_9BE63749F6F5__INCLUDED_)
