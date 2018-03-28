// SetVolume.h : main header file for the SETVOLUME application
//

#if !defined(AFX_SETVOLUME_H__91737439_C141_4115_9E1A_CD974CAE7A52__INCLUDED_)
#define AFX_SETVOLUME_H__91737439_C141_4115_9E1A_CD974CAE7A52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSetVolumeApp:
// See SetVolume.cpp for the implementation of this class
//

class CSetVolumeApp : public CWinApp
{
public:
	CSetVolumeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetVolumeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSetVolumeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETVOLUME_H__91737439_C141_4115_9E1A_CD974CAE7A52__INCLUDED_)
