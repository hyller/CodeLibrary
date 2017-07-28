// DyCtrlCreateDlg.h : header file
//

#if !defined(AFX_DYCTRLCREATEDLG_H__7657F20A_97C1_4E0E_A3F7_D8149DA6E7D5__INCLUDED_)
#define AFX_DYCTRLCREATEDLG_H__7657F20A_97C1_4E0E_A3F7_D8149DA6E7D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDyCtrlCreateDlg dialog

class CDyCtrlCreateDlg : public CDialog
{
// Construction
public:
	CDyCtrlCreateDlg(CWnd* pParent = NULL);	// standard constructor
    CEdit m_MyEdit;	 //编辑控件变量

// Dialog Data
	//{{AFX_DATA(CDyCtrlCreateDlg)
	enum { IDD = IDD_DYCTRLCREATE_DIALOG };
	CString	m_showmsg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDyCtrlCreateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
     


	// Generated message map functions
	//{{AFX_MSG(CDyCtrlCreateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonCreate();
	afx_msg void OnButtonDelete();
	afx_msg void OnChangeEdit();//用来响应编辑框改变的事件
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYCTRLCREATEDLG_H__7657F20A_97C1_4E0E_A3F7_D8149DA6E7D5__INCLUDED_)
