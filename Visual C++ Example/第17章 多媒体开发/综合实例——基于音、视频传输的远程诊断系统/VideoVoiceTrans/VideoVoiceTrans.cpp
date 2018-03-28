////////////////////////////////////////////////////////////////////////////
//
//
//    Project     : VideoVoiceTrans version 1.1.
//    Description : Peer to Peer Video Conferencing over the LAN.
//	  Author      :	Nagareshwar Y Talekar ( nsry2002@yahoo.co.in)
//    Date        : 15-6-2004.
//
//
//    File description : 
//    Name    :  VideoVoiceTrans.cpp
//    Details :  Main application class
//
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VideoVoiceTrans.h"
#include "VideoVoiceTransDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoVoiceTransApp

BEGIN_MESSAGE_MAP(CVideoVoiceTransApp, CWinApp)
	//{{AFX_MSG_MAP(CVideoVoiceTransApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoVoiceTransApp construction

CVideoVoiceTransApp::CVideoVoiceTransApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVideoVoiceTransApp object

CVideoVoiceTransApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CVideoVoiceTransApp initialization

BOOL CVideoVoiceTransApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	//----------------------------
	//For AppFace
	//Load From resource
	m_af.Start("IDR_FACEURF1",NULL,GTP_LOAD_RESOURCE,NULL,"faceurf") ;

	PBYTE buf = NULL ;  // Only used for load URF from Memory
	// Standard initialization
	//CAppFace af ; //line 1
//	af.Start(_T("IDR_MY_URF"),GTP_LOAD_RESOURCE,NULL,_T("MYRESTYPE"),NULL) ; //line 2
	//af.Start(_T("c:\\视频开发\\高\\gtbase.urf")) ;
	//af.Start(_T("IDR_MY_URF2"),GTP_LOAD_RESOURCE,NULL,_T("MYRESTYPE"),NULL) ; //line 2


	CVideoVoiceTransDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	
	//----------------------------
	//For AppFace
	if(buf) 
		delete [] buf ;
	
	m_af.Remove()  ;
	//----------------------------
	//af.Remove() ; //line 3
	return FALSE;
	

}
