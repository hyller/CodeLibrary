// StaticBMPMovie.h : main header file for the STATICBMPMOVIE application
//

#if !defined(AFX_STATICBMPMOVIE_H__9EA46A37_DF97_4CDA_941E_BABA6AB4C24F__INCLUDED_)
#define AFX_STATICBMPMOVIE_H__9EA46A37_DF97_4CDA_941E_BABA6AB4C24F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStaticBMPMovieApp:
// See StaticBMPMovie.cpp for the implementation of this class
//

class CStaticBMPMovieApp : public CWinApp
{
public:
	CStaticBMPMovieApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticBMPMovieApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStaticBMPMovieApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICBMPMOVIE_H__9EA46A37_DF97_4CDA_941E_BABA6AB4C24F__INCLUDED_)
