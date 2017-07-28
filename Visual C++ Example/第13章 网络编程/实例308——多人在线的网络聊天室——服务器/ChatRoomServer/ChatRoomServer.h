// ChatRoomServer.h : main header file for the CHATROOMSERVER application
//

#if !defined(AFX_CHATROOMSERVER_H__680EC642_E19B_4D55_88DF_2C9E9B1B30FD__INCLUDED_)
#define AFX_CHATROOMSERVER_H__680EC642_E19B_4D55_88DF_2C9E9B1B30FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChatRoomServerApp:
// See ChatRoomServer.cpp for the implementation of this class
//

class CChatRoomServerApp : public CWinApp
{
public:
	CChatRoomServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatRoomServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChatRoomServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATROOMSERVER_H__680EC642_E19B_4D55_88DF_2C9E9B1B30FD__INCLUDED_)
