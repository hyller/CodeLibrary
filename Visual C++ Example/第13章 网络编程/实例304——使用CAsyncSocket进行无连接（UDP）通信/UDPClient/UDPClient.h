// UDPClient.h : main header file for the UDPClient application
//

#if !defined(AFX_UDPClient_H__D015BF79_65B5_4C4E_8E7E_0122BB4F4AEE__INCLUDED_)
#define AFX_UDPClient_H__D015BF79_65B5_4C4E_8E7E_0122BB4F4AEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUDPClientApp:
// See UDPClient.cpp for the implementation of this class
//

class CUDPClientApp : public CWinApp
{
public:
	CUDPClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUDPClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPClient_H__D015BF79_65B5_4C4E_8E7E_0122BB4F4AEE__INCLUDED_)
