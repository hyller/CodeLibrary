// TextColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DlgDateExchange2.h"
#include "TextColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_SET_COLOR WM_USER+100//自定义消息
/////////////////////////////////////////////////////////////////////////////
// CTextColorDlg dialog


CTextColorDlg::CTextColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTextColorDlg::IDD, pParent)
{
	ASSERT(pParent);//窗口对象有效
	m_pParent=pParent;//获取窗口对象
	//{{AFX_DATA_INIT(CTextColorDlg)
	m_red = 0;
	m_green = 0;
	m_blue = 0;
	//}}AFX_DATA_INIT
}


void CTextColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextColorDlg)
	DDX_Text(pDX, IDC_EDIT1, m_red);
	DDV_MinMaxInt(pDX, m_red, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_green);
	DDV_MinMaxInt(pDX, m_green, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, m_blue);
	DDV_MinMaxInt(pDX, m_blue, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTextColorDlg, CDialog)
	//{{AFX_MSG_MAP(CTextColorDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextColorDlg message handlers

void CTextColorDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();//获取编辑框数据
	m_pParent->SendMessage(WM_SET_COLOR,(WPARAM)this);//发送自定义消息
	//CDialog::OnOK();
}

void CTextColorDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
