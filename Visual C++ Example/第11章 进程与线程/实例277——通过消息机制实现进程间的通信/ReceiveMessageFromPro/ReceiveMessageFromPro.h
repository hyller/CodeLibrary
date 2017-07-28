// ReceiveMessageFromPro.h : main header file for the RECEIVEMESSAGEFROMPRO application
//

#if !defined(AFX_RECEIVEMESSAGEFROMPRO_H__B2FD9446_E34A_4886_ACE6_6660A89DD810__INCLUDED_)
#define AFX_RECEIVEMESSAGEFROMPRO_H__B2FD9446_E34A_4886_ACE6_6660A89DD810__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReceiveMessageFromProApp:
// See ReceiveMessageFromPro.cpp for the implementation of this class
//

class CReceiveMessageFromProApp : public CWinApp
{
public:
	CReceiveMessageFromProApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReceiveMessageFromProApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReceiveMessageFromProApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECEIVEMESSAGEFROMPRO_H__B2FD9446_E34A_4886_ACE6_6660A89DD810__INCLUDED_)
