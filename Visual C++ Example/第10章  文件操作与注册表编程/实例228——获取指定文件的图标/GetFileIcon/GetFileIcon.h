// GetFileIcon.h : main header file for the GETFILEICON application
//

#if !defined(AFX_GETFILEICON_H__A2D495FB_E001_4846_917C_321597CA0F93__INCLUDED_)
#define AFX_GETFILEICON_H__A2D495FB_E001_4846_917C_321597CA0F93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetFileIconApp:
// See GetFileIcon.cpp for the implementation of this class
//

class CGetFileIconApp : public CWinApp
{
public:
	CGetFileIconApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetFileIconApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetFileIconApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETFILEICON_H__A2D495FB_E001_4846_917C_321597CA0F93__INCLUDED_)
