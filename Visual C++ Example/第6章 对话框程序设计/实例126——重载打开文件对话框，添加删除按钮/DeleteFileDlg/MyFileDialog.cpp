// MyFileDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DeleteFileDlg.h"
#include "MyFileDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFileDialog

IMPLEMENT_DYNAMIC(CMyFileDialog, CFileDialog)

CMyFileDialog::CMyFileDialog():
		CFileDialog(TRUE, NULL, NULL, OFN_FILEMUSTEXIST|OFN_ENABLETEMPLATE,NULL,NULL)
{
		SetTemplate(IDD_MYFILEDLG,IDD_MYFILEDLG);//设置文件对话框的模板为IDD_MYFILEDLG
}


BEGIN_MESSAGE_MAP(CMyFileDialog, CFileDialog)
	//{{AFX_MSG_MAP(CMyFileDialog)
	ON_BN_CLICKED(IDC_DLETEFILE, OnDletefile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CMyFileDialog::OnDletefile() 
{
	// TODO: Add your control notification handler code here
	CString pathName = GetPathName();//获取选中文件
	if(pathName.IsEmpty())
	{
		AfxMessageBox("没有选中文件！");
		return;
	}
	if(MessageBox("确定删除文件？","提示",MB_OKCANCEL)!=IDOK)
	{
		return;//不删除文件退出
	}
	CFile::Remove(pathName);
	GetDlgItem(IDC_STATIC1)->SetWindowText("删除文件"+pathName);	
}
