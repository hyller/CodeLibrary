// WavOutPlay.h : main header file for the WavOutPlay application
//

#if !defined(AFX_WavOutPlay_H__BC6FE36C_B873_4519_94D6_0C5B069F8AE0__INCLUDED_)
#define AFX_WavOutPlay_H__BC6FE36C_B873_4519_94D6_0C5B069F8AE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWavOutPlayApp:
// See WavOutPlay.cpp for the implementation of this class
//

class CWavOutPlayApp : public CWinApp
{
public:
	CWavOutPlayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWavOutPlayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWavOutPlayApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WavOutPlay_H__BC6FE36C_B873_4519_94D6_0C5B069F8AE0__INCLUDED_)
