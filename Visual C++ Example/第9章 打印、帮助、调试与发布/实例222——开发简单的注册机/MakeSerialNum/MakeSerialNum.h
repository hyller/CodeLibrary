// MakeSerialNum.h : main header file for the MAKESERIALNUM application
//

#if !defined(AFX_MAKESERIALNUM_H__D1B38C52_2071_4F62_9BAF_B5F5CE8AC08E__INCLUDED_)
#define AFX_MAKESERIALNUM_H__D1B38C52_2071_4F62_9BAF_B5F5CE8AC08E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMakeSerialNumApp:
// See MakeSerialNum.cpp for the implementation of this class
//

class CMakeSerialNumApp : public CWinApp
{
public:
	CMakeSerialNumApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMakeSerialNumApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMakeSerialNumApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAKESERIALNUM_H__D1B38C52_2071_4F62_9BAF_B5F5CE8AC08E__INCLUDED_)
