// FindDlgDemoDlg.h : header file
//

#if !defined(AFX_FINDDLGDEMODLG_H__DDC59574_D290_4471_BC7F_B7B2E44C86A2__INCLUDED_)
#define AFX_FINDDLGDEMODLG_H__DDC59574_D290_4471_BC7F_B7B2E44C86A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFindDlgDemoDlg dialog

class CFindDlgDemoDlg : public CDialog
{
// Construction
public:
	CFindDlgDemoDlg(CWnd* pParent = NULL);	// standard constructor
	CFindReplaceDialog *pFindReplaceDlg;						//查找替换对话框
	int pos;//记录查找字符串位置
	int curpos;
// Dialog Data
	//{{AFX_DATA(CFindDlgDemoDlg)
	enum { IDD = IDD_FINDDLGDEMO_DIALOG };
	CEdit	m_ctlEdit;
	CString	m_str;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindDlgDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	afx_msg LRESULT OnFindReplace(WPARAM, LPARAM lParam);//回调函数
	// Generated message map functions
	//{{AFX_MSG(CFindDlgDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDDLGDEMODLG_H__DDC59574_D290_4471_BC7F_B7B2E44C86A2__INCLUDED_)
