// reatReport.cpp : implementation file
//

#include "stdafx.h"
#include "VideoVoiceTrans.h"
#include "reatReport.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CreatReport dialog


CreatReport::CreatReport(CWnd* pParent /*=NULL*/)
	: CDialog(CreatReport::IDD, pParent)
{
	//{{AFX_DATA_INIT(CreatReport)
	m_Address = _T("");
	m_Type = _T("");
	m_Name = _T("");
	m_Scribe = _T("");
	m_Reporter = _T("");
	m_Data = 0;
	//}}AFX_DATA_INIT
}


void CreatReport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CreatReport)
	DDX_Text(pDX, IDC_ADDRESS, m_Address);
	DDV_MaxChars(pDX, m_Address, 30);
	DDX_Text(pDX, IDC_CODE, m_Type);
	DDV_MaxChars(pDX, m_Type, 30);
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDV_MaxChars(pDX, m_Name, 30);
	DDX_Text(pDX, IDC_SCRIBE, m_Scribe);
	DDX_Text(pDX, IDC_REPORTNAME, m_Reporter);
	DDV_MaxChars(pDX, m_Reporter, 6);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_Data);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CreatReport, CDialog)
	//{{AFX_MSG_MAP(CreatReport)
	ON_BN_CLICKED(IDC_SAVEREPORT, OnSavereport)
	ON_BN_CLICKED(IDC_DATABASE, OnDatabase)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CreatReport message handlers

void CreatReport::OnSavereport() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_Address.IsEmpty())
	{
		AfxMessageBox("请输入支援单位名称！");
		return;
	}
	if(m_Type.IsEmpty())
	{
		AfxMessageBox("请输入装备型号！");
		return;
	}
	if(m_Name.IsEmpty())
	{
		AfxMessageBox("请输入装备名称！");
		return;
	}
	if(m_Scribe.IsEmpty())
	{
		AfxMessageBox("请输入诊断过程！");
		return;
	}
	
	if(m_Reporter.IsEmpty())
	{
		AfxMessageBox("请输入报告人姓名！");
		return;
	}
	//打开文件对话框
	CFileDialog myFileDlg(FALSE,"txt",_T("诊断报告文件"),NULL,"Text(*.txt|All Files(*.*)|*.*||)",NULL);
//	myFileDlg.m_ofn.lpstrFileTitle=_T("请选择保存路径：");
	CString strfilename;
	if(myFileDlg.DoModal()!=IDOK)
		return;
	strfilename=myFileDlg.GetFileName();
	CStdioFile ExportFile;
	ExportFile.Open(strfilename,CFile::modeCreate | CFile::modeWrite,NULL);
	//CString time;
	CTime t=CTime::GetCurrentTime();
	CString time="诊断报告创建时间：    20%y-%m-%d%H:%M:%S";
	time=t.Format(time);
	ExportFile.WriteString(time+"\n\n");
	ExportFile.WriteString("支援单位：    "+m_Address+"\n\n");
	ExportFile.WriteString("装备型号：    "+m_Type+"\n\n");
	ExportFile.WriteString("装备名称：    "+m_Name+"\n\n");
	ExportFile.WriteString("诊断过程： \n\n         "+m_Scribe+"\n\n");
	ExportFile.WriteString("报告人：     "+m_Reporter+"\n\n");
	CString strdata="20%y-%m-%d";
	strdata=m_Data.Format(strdata);
	ExportFile.WriteString("支援时间：    "+strdata+"\n\n");
	ExportFile.Close();
	AfxMessageBox("报告生成成功！");


}

void CreatReport::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CreatReport::OnDatabase() 
{
	// TODO: Add your control notification handler code here
	
}

void CreatReport::OnClear() 
{
	// TODO: Add your control notification handler code here
	m_Address = _T("");
	m_Type = _T("");
	m_Name = _T("");
	m_Scribe = _T("");
	m_Reporter = _T("");
	m_Data = 0;
	UpdateData(false);
	
}
