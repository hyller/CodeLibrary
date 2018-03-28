// DriverSerialNum.h : main header file for the DRIVERSERIALNUM application
//

#if !defined(AFX_DRIVERSERIALNUM_H__40AE9467_1071_4D9F_8097_A2254431EB2D__INCLUDED_)
#define AFX_DRIVERSERIALNUM_H__40AE9467_1071_4D9F_8097_A2254431EB2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDriverSerialNumApp:
// See DriverSerialNum.cpp for the implementation of this class
//

class CDriverSerialNumApp : public CWinApp
{
public:
	CDriverSerialNumApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriverSerialNumApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDriverSerialNumApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVERSERIALNUM_H__40AE9467_1071_4D9F_8097_A2254431EB2D__INCLUDED_)
