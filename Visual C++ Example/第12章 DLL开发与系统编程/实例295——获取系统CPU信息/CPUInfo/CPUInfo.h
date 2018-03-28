// CPUInfo.h : main header file for the CPUINFO application
//

#if !defined(AFX_CPUINFO_H__170226F0_B8B2_4339_8CB8_D83920D3BFB8__INCLUDED_)
#define AFX_CPUINFO_H__170226F0_B8B2_4339_8CB8_D83920D3BFB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCPUInfoApp:
// See CPUInfo.cpp for the implementation of this class
//

class CCPUInfoApp : public CWinApp
{
public:
	CCPUInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCPUInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCPUInfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUINFO_H__170226F0_B8B2_4339_8CB8_D83920D3BFB8__INCLUDED_)
