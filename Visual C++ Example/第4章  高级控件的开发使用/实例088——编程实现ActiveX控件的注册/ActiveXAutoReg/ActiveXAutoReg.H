// ActiveXAutoReg.h : main header file for the ActiveXAutoReg application
//

#if !defined(AFX_ActiveXAutoReg_H__7DB947A4_172B_4108_B075_1AB118FEB90C__INCLUDED_)
#define AFX_ActiveXAutoReg_H__7DB947A4_172B_4108_B075_1AB118FEB90C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CActiveXAutoRegApp:
// See ActiveXAutoReg.cpp for the implementation of this class
//

class CActiveXAutoRegApp : public CWinApp
{
public:
	CActiveXAutoRegApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CActiveXAutoRegApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CActiveXAutoRegApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ActiveXAutoReg_H__7DB947A4_172B_4108_B075_1AB118FEB90C__INCLUDED_)
