// BeepVoice.h : main header file for the BEEPVOICE application
//

#if !defined(AFX_BEEPVOICE_H__221BDFC2_689C_40A2_AF84_FA26265CE177__INCLUDED_)
#define AFX_BEEPVOICE_H__221BDFC2_689C_40A2_AF84_FA26265CE177__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBeepVoiceApp:
// See BeepVoice.cpp for the implementation of this class
//

class CBeepVoiceApp : public CWinApp
{
public:
	CBeepVoiceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBeepVoiceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBeepVoiceApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BEEPVOICE_H__221BDFC2_689C_40A2_AF84_FA26265CE177__INCLUDED_)
