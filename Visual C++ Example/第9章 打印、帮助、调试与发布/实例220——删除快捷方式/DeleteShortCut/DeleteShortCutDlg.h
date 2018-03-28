// DeleteShortCutDlg.h : header file
//

#if !defined(AFX_DeleteShortCutDLG_H__F768FF90_F6F4_46B2_B8F5_1107A2CA3608__INCLUDED_)
#define AFX_DeleteShortCutDLG_H__F768FF90_F6F4_46B2_B8F5_1107A2CA3608__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CDeleteShortCutDlg dialog

class CDeleteShortCutDlg : public CDialog
{
// Construction
public:
	CDeleteShortCutDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteShortCutDlg)
	enum { IDD = IDD_DeleteShortCut_DIALOG };
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteShortCutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	
	int nBeginAt;//起始文件夹的PIDL	
	BOOL GetShortcutDel(LPSTR lpszInitDir,LPSTR lpszShortcut);//取得要创建的快捷方式的名字
	//删除快捷方式
	BOOL DeleteLink( LPSTR lpszShortcut);
	// 通知shell有关变化
	void NotifyShell(LONG wEventId,//事件标志
            LPSTR szPath);//路径
	// Generated message map functions
	//{{AFX_MSG(CDeleteShortCutDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DeleteShortCutDLG_H__F768FF90_F6F4_46B2_B8F5_1107A2CA3608__INCLUDED_)
