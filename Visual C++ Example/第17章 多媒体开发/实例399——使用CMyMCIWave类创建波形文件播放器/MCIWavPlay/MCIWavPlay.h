// MCIWavPlay.h : main header file for the MCIWavPlay application
//

#if !defined(AFX_MCIWavPlay_H__3E0DFC41_532B_4BDB_9601_CC945DB9F5A4__INCLUDED_)
#define AFX_MCIWavPlay_H__3E0DFC41_532B_4BDB_9601_CC945DB9F5A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMCIWavPlayApp:
// See MCIWavPlay.cpp for the implementation of this class
//

class CMCIWavPlayApp : public CWinApp
{
public:
	CMCIWavPlayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMCIWavPlayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMCIWavPlayApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCIWavPlay_H__3E0DFC41_532B_4BDB_9601_CC945DB9F5A4__INCLUDED_)
