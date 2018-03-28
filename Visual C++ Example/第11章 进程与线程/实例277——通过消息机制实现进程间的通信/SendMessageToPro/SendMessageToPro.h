// SendMessageToPro.h : main header file for the SENDMESSAGETOPRO application
//

#if !defined(AFX_SENDMESSAGETOPRO_H__26A44F26_D7CF_4F5D_A069_C10408C0CE3B__INCLUDED_)
#define AFX_SENDMESSAGETOPRO_H__26A44F26_D7CF_4F5D_A069_C10408C0CE3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSendMessageToProApp:
// See SendMessageToPro.cpp for the implementation of this class
//

class CSendMessageToProApp : public CWinApp
{
public:
	CSendMessageToProApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendMessageToProApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSendMessageToProApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDMESSAGETOPRO_H__26A44F26_D7CF_4F5D_A069_C10408C0CE3B__INCLUDED_)
