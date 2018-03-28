// ADODataBase1.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ADODataBase1.h"
#include "ADODataBase1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADODataBase1App

BEGIN_MESSAGE_MAP(CADODataBase1App, CWinApp)
	//{{AFX_MSG_MAP(CADODataBase1App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADODataBase1App construction

CADODataBase1App::CADODataBase1App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CADODataBase1App object

CADODataBase1App theApp;

/////////////////////////////////////////////////////////////////////////////
// CADODataBase1App initialization

BOOL CADODataBase1App::InitInstance()
{
	AfxEnableControlContainer();
	//初始化OLE DLLs
	if (!AfxOleInit())
	{
		AfxMessageBox("初始化OLE DLL失败！");
		return FALSE;
	}
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CADODataBase1Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.

	return FALSE;
}
