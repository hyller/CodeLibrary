// ChatRoomClient.h : main header file for the CHATROOMCLIENT application
//

#if !defined(AFX_CHATROOMCLIENT_H__4503F0DD_CA95_4F24_B6EE_3183B64B095B__INCLUDED_)
#define AFX_CHATROOMCLIENT_H__4503F0DD_CA95_4F24_B6EE_3183B64B095B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChatRoomClientApp:
// See ChatRoomClient.cpp for the implementation of this class
//

class CChatRoomClientApp : public CWinApp
{
public:
	CChatRoomClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatRoomClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChatRoomClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATROOMCLIENT_H__4503F0DD_CA95_4F24_B6EE_3183B64B095B__INCLUDED_)
