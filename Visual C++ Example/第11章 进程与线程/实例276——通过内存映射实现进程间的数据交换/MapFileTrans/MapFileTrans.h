// MapFileTrans.h : main header file for the MAPFILETRANS application
//

#if !defined(AFX_MAPFILETRANS_H__2D124B0B_D0DC_403A_BDF9_4989FDFC45DC__INCLUDED_)
#define AFX_MAPFILETRANS_H__2D124B0B_D0DC_403A_BDF9_4989FDFC45DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMapFileTransApp:
// See MapFileTrans.cpp for the implementation of this class
//

class CMapFileTransApp : public CWinApp
{
public:
	CMapFileTransApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapFileTransApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMapFileTransApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPFILETRANS_H__2D124B0B_D0DC_403A_BDF9_4989FDFC45DC__INCLUDED_)
