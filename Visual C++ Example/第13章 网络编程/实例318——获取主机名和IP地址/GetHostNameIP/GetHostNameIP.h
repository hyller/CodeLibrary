// GetHostNameIP.h : main header file for the GETHOSTNAMEIP application
//

#if !defined(AFX_GETHOSTNAMEIP_H__60B2B4B4_CBA1_4839_9A13_951BB8CF8495__INCLUDED_)
#define AFX_GETHOSTNAMEIP_H__60B2B4B4_CBA1_4839_9A13_951BB8CF8495__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetHostNameIPApp:
// See GetHostNameIP.cpp for the implementation of this class
//

class CGetHostNameIPApp : public CWinApp
{
public:
	CGetHostNameIPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetHostNameIPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetHostNameIPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETHOSTNAMEIP_H__60B2B4B4_CBA1_4839_9A13_951BB8CF8495__INCLUDED_)
