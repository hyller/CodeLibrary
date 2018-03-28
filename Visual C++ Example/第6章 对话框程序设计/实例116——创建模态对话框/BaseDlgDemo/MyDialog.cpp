// MyDialog.cpp : implementation file
//

#include "stdafx.h"
#include "BaseDlgDemo.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MyDialog dialog


MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MyDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(MyDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MyDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
	//{{AFX_MSG_MAP(MyDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyDialog message handlers

void MyDialog::OnButton1() //确定按钮
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();//调用OnOK()函数退出对话框
	
}

void MyDialog::OnButton2() //取消按钮
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();//调用OnCancel()函数退出对话框
}

void MyDialog::OnButton3() //关闭按钮
{
	// TODO: Add your control notification handler code here
	int nRet = 5; // 自定义返回值
	CDialog::EndDialog(nRet); // 调用EndDialog退出对话框
}
