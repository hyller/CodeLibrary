// TimeLimit.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TimeLimit.h"
#include "TimeLimitDlg.h"
#include "RegKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeLimitApp

BEGIN_MESSAGE_MAP(CTimeLimitApp, CWinApp)
	//{{AFX_MSG_MAP(CTimeLimitApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeLimitApp construction

CTimeLimitApp::CTimeLimitApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTimeLimitApp object

CTimeLimitApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTimeLimitApp initialization

BOOL CTimeLimitApp::InitInstance()
{
	
	CTime CurTime = CTime::GetCurrentTime();//先获得当前的系统时间
	if (!IsInstalled())//检查软件是否第一次运行，如果是则设定限制时间
	{
		CTime t = CurTime + CTimeSpan(0,0,5,0); //使用时限为5分钟  
		SetLimitTime(t.GetYear(),t.GetMonth(),t.GetDay(),
			         t.GetHour(),t.GetMinute(),t.GetSecond());
	}
	else
	{
		//如果软件不是第一次运行，读取注册表中的时间值，与当前时间比较
		CTime LimitTime;
		GetLimitTime(LimitTime);
		if (CurTime>LimitTime)//超过了使用期限
		{
			AfxMessageBox("试用版已到期，请联系购买一个正版使用",MB_OK);
			return FALSE;//退出
		}
	}
   
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CTimeLimitDlg dlg;
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


BOOL CTimeLimitApp::IsInstalled()//判定软件是否为第一次运行
{
	BOOL bInstalled = FALSE;
	DWORD dwDisposition;
	HKEY m_hKey;
	//打开注册表
	LONG ret = RegCreateKeyEx (HKEY_LOCAL_MACHINE, "SOFTWARE\\TimeLimit", 0L, NULL,
		REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, &m_hKey, &dwDisposition);
    if (ret != ERROR_SUCCESS)    //打开注册表失败
		return FALSE;
	//从注册表中读入特征值
	DWORD dwVal,dwType,dwLen;
	ret = RegQueryValueEx(m_hKey, "Installed", NULL, &dwType,(unsigned char*)&dwVal,&dwLen);
    if (ret != ERROR_SUCCESS)      //读取数据失败
		return FALSE;                        
	//检查读到的特征值是否为1，如果是，则表明软件以前已运行过
	bInstalled = (dwVal == 1);	
	RegCloseKey(m_hKey);//关闭注册表
	return bInstalled;
}


BOOL CTimeLimitApp::GetLimitTime(CTime&t)
{
	DWORD dwDisposition;
	HKEY m_hKey;
	//打开注册表
	LONG ret = RegCreateKeyEx (HKEY_LOCAL_MACHINE, "SOFTWARE\\TimeLimit", 0L, NULL,
		REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, &m_hKey, &dwDisposition);
    if (ret != ERROR_SUCCESS)    //打开注册表失败
		return FALSE;	
	//从注册表中读入试用期限数据
	DWORD nYear,nMonth,nDay,nHour,nMinute,nSecond;
	DWORD dwType;
	DWORD dwLen;
	ret = RegQueryValueEx (m_hKey, "Year", NULL,    //读取年份
		&dwType,(unsigned char*)&nYear,&dwLen);
    if (ret != ERROR_SUCCESS)      //读取数据失败
		return FALSE;                        
	ret = RegQueryValueEx (m_hKey, "Month", NULL,    //读取月份
		&dwType,(unsigned char*)&nMonth,&dwLen);
    if (ret != ERROR_SUCCESS)      //读取数据失败
		return FALSE;                        
	ret = RegQueryValueEx (m_hKey, "Day", NULL,    //读取天
		&dwType,(unsigned char*)&nDay,&dwLen);
    if (ret != ERROR_SUCCESS)      //读取数据失败
		return FALSE;                        
	ret = RegQueryValueEx (m_hKey, "Hour", NULL,    //读取小时
		&dwType,(unsigned char*)&nHour,&dwLen);
    if (ret != ERROR_SUCCESS)      //读取数据失败
		return FALSE;                        
	ret = RegQueryValueEx (m_hKey, "Minute", NULL,    //读取分钟
		&dwType,(unsigned char*)&nMinute,&dwLen);
    if (ret != ERROR_SUCCESS)      //读取数据失败
		return FALSE;                        
	ret = RegQueryValueEx (m_hKey, "Second", NULL,    //读取秒
		&dwType,(unsigned char*)&nSecond,&dwLen);
    if (ret != ERROR_SUCCESS)                         //读取数据失败
		return FALSE;                        	
	//关闭注册表
	RegCloseKey(m_hKey);
	t = CTime(nYear,nMonth,nDay,nHour,nMinute,nSecond);
	return TRUE;
}

BOOL CTimeLimitApp::SetLimitTime(DWORD nYear,DWORD nMonth,DWORD nDay,
		              DWORD nHour,DWORD nMinute,DWORD nSecond)
{
    DWORD dwDisposition;
	HKEY m_hKey;
	//打开注册表
	LONG ret = RegCreateKeyEx (HKEY_LOCAL_MACHINE, "SOFTWARE\\TimeLimit", 0L, NULL,
		REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, &m_hKey, &dwDisposition);
    if (ret != ERROR_SUCCESS)    //打开注册表失败
		return FALSE;	
	//向注册表中写入试用期限数据
	ret = RegSetValueEx (m_hKey, "Year", NULL,      //写入年
		REG_DWORD,(CONST BYTE*)&nYear,sizeof(DWORD));
    if (ret != ERROR_SUCCESS)                       //写入数据失败       
		return FALSE;                        
	ret = RegSetValueEx (m_hKey, "Month", NULL,     //写入月份
		REG_DWORD,(CONST BYTE*)&nMonth,sizeof(DWORD));
    if (ret != ERROR_SUCCESS)                       //写入数据失败
		return FALSE;                        
	ret = RegSetValueEx (m_hKey, "Day", NULL,       //写入天
		REG_DWORD,(CONST BYTE*)&nDay,sizeof(DWORD));
    if (ret != ERROR_SUCCESS)                       //写入数据失败
		return FALSE;                        
	ret = RegSetValueEx (m_hKey, "Hour", NULL,      //写入小时
		REG_DWORD,(CONST BYTE*)&nHour,sizeof(DWORD));
    if (ret != ERROR_SUCCESS)                       //写入数据失败
		return FALSE;                        
	ret = RegSetValueEx (m_hKey, "Minute", NULL,    //读取分钟数据
		REG_DWORD,(CONST BYTE*)&nMinute,sizeof(DWORD));
    if (ret != ERROR_SUCCESS)                       //写入数据失败
		return FALSE;                        
	ret = RegSetValueEx (m_hKey, "Second", NULL,    //写入秒
		REG_DWORD,(CONST BYTE*)&nSecond,sizeof(DWORD));
    if (ret != ERROR_SUCCESS)                       //写入数据失败
		return FALSE;    	
	//写入特征数据，表明不是第一次使用
	DWORD dwVal = 1;
	ret = RegSetValueEx (m_hKey, "Installed", NULL,    //写入特征值
		REG_DWORD,(CONST BYTE*)&dwVal,sizeof(DWORD));
    if (ret != ERROR_SUCCESS)				//写入数据失败
		return FALSE;                 	
	RegCloseKey(m_hKey);	//关闭注册表
	return TRUE;  
}
