// ShowChangeFBLDlg.h : header file
//

#if !defined(AFX_SHOWCHANGEFBLDLG_H__DC782C19_3F7D_4602_8939_2856240BB402__INCLUDED_)
#define AFX_SHOWCHANGEFBLDLG_H__DC782C19_3F7D_4602_8939_2856240BB402__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShowChangeFBLDlg dialog

class CShowChangeFBLDlg : public CDialog
{
// Construction
public:
	CShowChangeFBLDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShowChangeFBLDlg)
	enum { IDD = IDD_SHOWCHANGEFBL_DIALOG };
	CComboBox	m_ctlCombo3;
	CComboBox	m_ctlCombo2;
	CComboBox	m_ctlCombo1;
	CString	m_strCurcolor;
	CString	m_strCurdif;
	CString	m_strCurrefresh;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowChangeFBLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShowChangeFBLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWCHANGEFBLDLG_H__DC782C19_3F7D_4602_8939_2856240BB402__INCLUDED_)
