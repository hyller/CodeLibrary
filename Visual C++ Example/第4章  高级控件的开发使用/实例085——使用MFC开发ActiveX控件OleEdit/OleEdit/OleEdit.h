#if !defined(AFX_OLEEDIT_H__BB377575_0838_44FB_828F_6639F558BCC2__INCLUDED_)
#define AFX_OLEEDIT_H__BB377575_0838_44FB_828F_6639F558BCC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// OleEdit.h : main header file for OLEEDIT.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COleEditApp : See OleEdit.cpp for implementation.

class COleEditApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEEDIT_H__BB377575_0838_44FB_828F_6639F558BCC2__INCLUDED)
