// CreateShortCutDlg.h : header file
//

#if !defined(AFX_CREATESHORTCUTDLG_H__F768FF90_F6F4_46B2_B8F5_1107A2CA3608__INCLUDED_)
#define AFX_CREATESHORTCUTDLG_H__F768FF90_F6F4_46B2_B8F5_1107A2CA3608__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CCreateShortCutDlg dialog

class CCreateShortCutDlg : public CDialog
{
// Construction
public:
	CCreateShortCutDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateShortCutDlg)
	enum { IDD = IDD_CREATESHORTCUT_DIALOG };
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateShortCutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	
	int nBeginAt;//起始文件夹的PIDL	
	BOOL BrowseForFolder(
    LPITEMIDLIST pidlRoot,//浏览开始处的PIDL
    LPITEMIDLIST *ppidlDestination, //浏览结束时所选择的PIDL
    LPCSTR lpszTitle);//浏览对话框中的提示文字
	BOOL SelectMenuItem( LPSTR szFileName);//取得快捷方式的目标应用程序名
	BOOL GetShortcutCrt(LPSTR szPath);//取得要创建的快捷方式的名字
	//创建快捷方式
	BOOL CreateLink ( 
		LPSTR szPath,//快捷方式的目标应用程序名
		LPSTR szLink);//快捷方式的数据文件名(*.lnk)
	// 通知shell有关变化
	void NotifyShell(LONG wEventId,//事件标志
            LPSTR szPath);//路径
	// Generated message map functions
	//{{AFX_MSG(CCreateShortCutDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATESHORTCUTDLG_H__F768FF90_F6F4_46B2_B8F5_1107A2CA3608__INCLUDED_)
