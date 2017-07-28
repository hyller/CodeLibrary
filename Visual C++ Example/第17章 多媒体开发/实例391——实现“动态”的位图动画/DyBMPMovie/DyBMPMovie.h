// DyBMPMovie.h : main header file for the DYBMPMOVIE application
//

#if !defined(AFX_DYBMPMOVIE_H__545283F3_40C8_460F_9EA2_905FEAC3688A__INCLUDED_)
#define AFX_DYBMPMOVIE_H__545283F3_40C8_460F_9EA2_905FEAC3688A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieApp:
// See DyBMPMovie.cpp for the implementation of this class
//

class CDyBMPMovieApp : public CWinApp
{
public:
	CDyBMPMovieApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDyBMPMovieApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDyBMPMovieApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYBMPMOVIE_H__545283F3_40C8_460F_9EA2_905FEAC3688A__INCLUDED_)
