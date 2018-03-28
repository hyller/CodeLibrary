// OperateAccessDlg.h : header file
//

#if !defined(AFX_OPERATEACCESSDLG_H__DA9B7314_A03B_45C2_A1A1_7EF8F525FAC6__INCLUDED_)
#define AFX_OPERATEACCESSDLG_H__DA9B7314_A03B_45C2_A1A1_7EF8F525FAC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COperateAccessDlg dialog

class COperateAccessDlg : public CDialog
{
// Construction
public:
	COperateAccessDlg(CWnd* pParent = NULL);	// standard constructor
	// 定义ADO连接、命令、记录集变量指针
	_ConnectionPtr	m_pConnection;
	_CommandPtr		m_pCommand;
	_RecordsetPtr	m_pRecordset;
// Dialog Data
	//{{AFX_DATA(COperateAccessDlg)
	enum { IDD = IDD_OPERATEACCESS_DIALOG };
	CListBox	m_ctlList;
	CString	m_strNo;
	CString	m_strName;
	CString	m_strSex;
	CString	m_strAddress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COperateAccessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COperateAccessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRead();
	afx_msg void OnModify();
	afx_msg void OnRemove();
	afx_msg void OnAdd();
	afx_msg void OnSelchangeList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPERATEACCESSDLG_H__DA9B7314_A03B_45C2_A1A1_7EF8F525FAC6__INCLUDED_)
