// OwnerMessage.h : main header file for the OWNERMESSAGE application
//

#if !defined(AFX_OWNERMESSAGE_H__C190AD46_E5AC_4771_906B_FDB5710C0881__INCLUDED_)
#define AFX_OWNERMESSAGE_H__C190AD46_E5AC_4771_906B_FDB5710C0881__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COwnerMessageApp:
// See OwnerMessage.cpp for the implementation of this class
//

class COwnerMessageApp : public CWinApp
{
public:
	COwnerMessageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COwnerMessageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COwnerMessageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OWNERMESSAGE_H__C190AD46_E5AC_4771_906B_FDB5710C0881__INCLUDED_)
