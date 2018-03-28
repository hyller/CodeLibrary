// NewDialogBar.cpp : implementation file
//

#include "stdafx.h"
#include "CMDDialogBar.h"
#include "NewDialogBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewDialogBar dialog


CNewDialogBar::CNewDialogBar(CWnd* pParent /*=NULL*/)
{
	//{{AFX_DATA_INIT(CNewDialogBar)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNewDialogBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewDialogBar)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewDialogBar, CDialogBar)
	//{{AFX_MSG_MAP(CNewDialogBar)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_COMMAND(ID_MENU1, OnMenu1)
	ON_COMMAND(ID_MENU2, OnMenu2)
	ON_COMMAND(ID_MENU3, OnMenu3)
	ON_COMMAND(ID_MENU4, OnMenu4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewDialogBar message handlers

BOOL CNewDialogBar::OnInitDialog() 
{
//DialogBar::OnInitDialog();
	
	// TODO: Add extra initialization here
	static char* str[]={"芝加哥公牛","密尔沃基雄鹿","亚特兰大鹰","费城76人"};
	CComboBox* pCBox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	for(int i=0;i<4;i++)
	{
		pCBox->AddString(str[i]);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNewDialogBar::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CComboBox* pCBox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	int nIndex=pCBox->GetCurSel();
	if(nIndex==CB_ERR)
		return;
	CStatic* pIcon=(CStatic*)GetDlgItem(IDC_STATIC1);
	HICON hIcon=AfxGetApp()->LoadIcon(IDI_ICON1+nIndex);
	pIcon->SetIcon(hIcon);
}

void CNewDialogBar::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString str;
	CComboBox* pCBox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	int nselect=pCBox->GetCurSel();				//获取当前组合框选项的索引
	pCBox->GetLBText(nselect,str);			//静态文本显示当前组合框选项的标题
	AfxMessageBox("当前选择："+str);
	
}

void CNewDialogBar::OnMenu1() 
{
	// TODO: Add your command handler code here
	CComboBox* pCBox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	pCBox->SetCurSel(0);	
	UpdateData(false);
	CStatic* pIcon=(CStatic*)GetDlgItem(IDC_STATIC1);
	HICON hIcon=AfxGetApp()->LoadIcon(IDI_ICON1);
	pIcon->SetIcon(hIcon);

}

void CNewDialogBar::OnMenu2() 
{
	// TODO: Add your command handler code here
	CComboBox* pCBox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	pCBox->SetCurSel(1);	
	UpdateData(false);
	CStatic* pIcon=(CStatic*)GetDlgItem(IDC_STATIC1);
	HICON hIcon=AfxGetApp()->LoadIcon(IDI_ICON2);
	pIcon->SetIcon(hIcon);
	
}

void CNewDialogBar::OnMenu3() 
{
	// TODO: Add your command handler code here
	CComboBox* pCBox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	pCBox->SetCurSel(2);	
	UpdateData(false);
	CStatic* pIcon=(CStatic*)GetDlgItem(IDC_STATIC1);
	HICON hIcon=AfxGetApp()->LoadIcon(IDI_ICON3);
	pIcon->SetIcon(hIcon);
	
}

void CNewDialogBar::OnMenu4() 
{
	// TODO: Add your command handler code here
	CComboBox* pCBox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	pCBox->SetCurSel(3);	
	UpdateData(false);
	CStatic* pIcon=(CStatic*)GetDlgItem(IDC_STATIC1);
	HICON hIcon=AfxGetApp()->LoadIcon(IDI_ICON4);
	pIcon->SetIcon(hIcon);
	
}
