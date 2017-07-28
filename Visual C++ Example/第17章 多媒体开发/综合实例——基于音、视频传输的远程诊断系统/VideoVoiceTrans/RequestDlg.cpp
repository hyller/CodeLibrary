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
//    Name    : RequestDlg.cpp
//    Details : Dialog box which display accept/reject choice , when 
//				invitation from remote host arrives.
//
/////////////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "VideoVoiceTrans.h"
#include "RequestDlg.h"
#include "VideoVoiceTransDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RequestDlg dialog


RequestDlg::RequestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(RequestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(RequestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void RequestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RequestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RequestDlg, CDialog)
	//{{AFX_MSG_MAP(RequestDlg)
	ON_BN_CLICKED(IDOK, OnAccept)
	ON_BN_CLICKED(IDREJECT, OnReject)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()





BOOL RequestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	char str[600];
	sprintf(str,"用户 %s 请求建立连接",rname);

	this->SetDlgItemText(IDC_MESG,str);
	
	return TRUE;
}


/**
*    Set remote user name and address
*/  

void RequestDlg::SetParameter(char *hostname,char *hostaddress,CDialog *dlg) 
{

strcpy(rname,hostname);
strcpy(raddress,hostaddress);
pdlg=dlg;
	
}


/**
*    User has accepted the connection request
*    Now send acceptance request to remote user
*    and start the conference
*/  

void RequestDlg::OnAccept() 
{
	this->OnCancel();
	//向对端发送MESG_ACCEPT消息
	((CVideoVoiceTransDlg*)pdlg)->dcontrol.SendControlMessage(MESG_ACCEPT,NULL);
	// Start the conference...
	((CVideoVoiceTransDlg*)pdlg)->StartConference();//本端交互程序启动
}



/**
*    User has rejected  the connection request
*    Now send reject notification request to remote user
*/  

void RequestDlg::OnReject() 
{
	
	// Send notification to remote user
	((CVideoVoiceTransDlg*)pdlg)->dcontrol.SendControlMessage(MESG_REJECT,NULL);


	CDialog::OnCancel();
}
