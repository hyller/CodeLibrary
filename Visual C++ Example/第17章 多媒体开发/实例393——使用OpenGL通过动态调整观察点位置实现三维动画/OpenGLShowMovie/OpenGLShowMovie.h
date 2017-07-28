// OpenGLShowMovie.h : main header file for the OpenGLShowMovie application
//

#if !defined(AFX_OpenGLShowMovie_H__FD396FDA_9CA0_4B29_AD9D_6EB9DFBE969F__INCLUDED_)
#define AFX_OpenGLShowMovie_H__FD396FDA_9CA0_4B29_AD9D_6EB9DFBE969F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COpenGLShowMovieApp:
// See OpenGLShowMovie.cpp for the implementation of this class
//

class COpenGLShowMovieApp : public CWinApp
{
public:
	COpenGLShowMovieApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLShowMovieApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COpenGLShowMovieApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OpenGLShowMovie_H__FD396FDA_9CA0_4B29_AD9D_6EB9DFBE969F__INCLUDED_)
