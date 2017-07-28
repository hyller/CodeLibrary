// REQUESTCON.cpp : implementation file
//

#include "stdafx.h"
#include "VideoVoiceTrans.h"
#include "REQUESTCON.h"
#include "VideoVoiceTransDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// REQUESTCON dialog


REQUESTCON::REQUESTCON(CWnd* pParent /*=NULL*/)
	: CDialog(REQUESTCON::IDD, pParent)
{
	//{{AFX_DATA_INIT(REQUESTCON)
	m_Armname = _T("");
	m_Code = _T("");
	m_Name = _T("");
	m_Requestname = _T("");
	m_telephone = _T("");
	m_Dept = _T("");
	//}}AFX_DATA_INIT
}


void REQUESTCON::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(REQUESTCON)
	DDX_Text(pDX, IDC_ARMNAME, m_Armname);
	DDV_MaxChars(pDX, m_Armname, 30);
	DDX_Text(pDX, IDC_CODE, m_Code);
	DDV_MaxChars(pDX, m_Code, 30);
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDV_MaxChars(pDX, m_Name, 30);
	DDX_Text(pDX, IDC_REQUESTNAME, m_Requestname);
	DDV_MaxChars(pDX, m_Requestname, 6);
	DDX_Text(pDX, IDC_TELEPHONE, m_telephone);
	DDV_MaxChars(pDX, m_telephone, 15);
	DDX_Text(pDX, IDC_DEPT, m_Dept);
	DDV_MaxChars(pDX, m_Dept, 30);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(REQUESTCON, CDialog)
	//{{AFX_MSG_MAP(REQUESTCON)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// REQUESTCON message handlers

void REQUESTCON::SetParent(CDialog *dlg) 
{

mdlg=dlg;

}
void REQUESTCON::OnClear() 
{
	// TODO: Add your control notification handler code here
	m_Armname = _T("");
	m_Code = _T("");
	m_Name = _T("");
	m_Requestname = _T("");
	m_telephone = _T("");
	m_Dept = _T("");
	UpdateData(false);
	
}

void REQUESTCON::OnConnect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_Armname.IsEmpty())
	{
		AfxMessageBox("请输入单位名称！");
		return;
	}
	if(m_Requestname.IsEmpty())
	{
		AfxMessageBox("请输入请求人员姓名！");
		return;
	}
	if(m_Name.IsEmpty())
	{
		AfxMessageBox("请输入装备名称！");
		return;
	}
	if(m_telephone.IsEmpty())
	{
		AfxMessageBox("请输入联系电话！");
		return;
	}
	if(m_Code.IsEmpty())
	{
		m_Code="不详";
	}
	unsigned char *packet=new unsigned char[100];
	// Text message
	packet[0]=25;
	
	int n1,n2,n3,n4,n5,lenth;
	n1=strlen(m_Armname);
	n2=strlen(m_Requestname);
	n3=strlen(m_Name);
	n4=strlen(m_Code);
	n5=strlen(m_telephone);
	packet[1]=n1;
	packet[2]=n2;
	packet[3]=n3;
	packet[4]=n4;
	packet[5]=n5;
	lenth=n5+n4+n3+n2+n1+6;
	memcpy(&packet[6],m_Armname,n1);
	memcpy(&packet[n1+6],m_Requestname,n2);
	memcpy(&packet[n2+n1+6],m_Name,n3);
	memcpy(&packet[n3+n2+n1+6],m_Code,n4);
	memcpy(&packet[n4+n3+n2+n1+6],m_telephone,n5);
	this->OnCancel();

	((CVideoVoiceTransDlg*)mdlg)->drequest.SendRequestCon(packet,lenth);
	
}
