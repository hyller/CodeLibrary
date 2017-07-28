// ColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DlgDateExchange.h"
#include "ColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorDlg dialog


CColorDlg::CColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColorDlg)
	m_r = 0;
	m_g = 0;
	m_b = 0;
	//}}AFX_DATA_INIT
}


void CColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorDlg)
	DDX_Control(pDX, IDC_EDIT3, m_B);
	DDX_Control(pDX, IDC_EDIT2, m_G);
	DDX_Control(pDX, IDC_EDIT1, m_R);
	DDX_Text(pDX, IDC_EDIT1, m_r);
	DDV_MinMaxInt(pDX, m_r, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_g);
	DDV_MinMaxInt(pDX, m_g, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, m_b);
	DDV_MinMaxInt(pDX, m_b, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CColorDlg, CDialog)
	//{{AFX_MSG_MAP(CColorDlg)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorDlg message handlers

void CColorDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	m_R.EnableWindow(true);//激活各编辑框
	m_G.EnableWindow(true);
	m_B.EnableWindow(true);	
}

BOOL CColorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
	m_R.EnableWindow(false);//各编辑框初始为无效状态
	m_G.EnableWindow(false);
	m_B.EnableWindow(false);	
	return TRUE;  // return TRUE unless you set the focus to a control	              // EXCEPTION: OCX Property Pages should return FALSE
}
