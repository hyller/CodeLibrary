// EnumDeviceInfo.h : main header file for the ENUMDEVICEINFO application
//

#if !defined(AFX_ENUMDEVICEINFO_H__E7D52A76_D56A_43CF_A3EC_6A67D01FC707__INCLUDED_)
#define AFX_ENUMDEVICEINFO_H__E7D52A76_D56A_43CF_A3EC_6A67D01FC707__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnumDeviceInfoApp:
// See EnumDeviceInfo.cpp for the implementation of this class
//

class CEnumDeviceInfoApp : public CWinApp
{
public:
	CEnumDeviceInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumDeviceInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEnumDeviceInfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMDEVICEINFO_H__E7D52A76_D56A_43CF_A3EC_6A67D01FC707__INCLUDED_)
