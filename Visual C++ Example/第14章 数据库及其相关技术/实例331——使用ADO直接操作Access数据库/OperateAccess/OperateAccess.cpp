// OperateAccess.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "OperateAccess.h"
#include "OperateAccessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COperateAccessApp

BEGIN_MESSAGE_MAP(COperateAccessApp, CWinApp)
	//{{AFX_MSG_MAP(COperateAccessApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COperateAccessApp construction

COperateAccessApp::COperateAccessApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only COperateAccessApp object

COperateAccessApp theApp;

/////////////////////////////////////////////////////////////////////////////
// COperateAccessApp initialization

BOOL COperateAccessApp::InitInstance()
{
	AfxEnableControlContainer();
	// 初始化COM,创建ADO连接等操作
	AfxOleInit();
	m_pConnection.CreateInstance(__uuidof(Connection));

	// 在ADO操作中建议语句中要常用try...catch()来捕获错误信息,因为它有时会经常出现一些想不到的错误。
	try                 
	{	
		// 打开本地Access库student.mdb
		m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=student.mdb","","",adModeUnknown);
		
	}
	catch(_com_error e)
	{
		AfxMessageBox("数据库连接失败，确认数据库student.mdb是否在当前路径下!");
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

	COperateAccessDlg dlg;
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

int COperateAccessApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	// 关闭ADO连接状态
	if(m_pConnection->State)
		m_pConnection->Close();
	m_pConnection= NULL;
	return CWinApp::ExitInstance();
}
