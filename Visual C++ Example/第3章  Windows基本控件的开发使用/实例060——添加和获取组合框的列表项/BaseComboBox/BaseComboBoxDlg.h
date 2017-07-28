// BaseComboBoxDlg.h : header file
//

#if !defined(AFX_BASECOMBOBOXDLG_H__A0E51BAE_5665_4816_A183_AE9693038F6B__INCLUDED_)
#define AFX_BASECOMBOBOXDLG_H__A0E51BAE_5665_4816_A183_AE9693038F6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBaseComboBoxDlg dialog

class CBaseComboBoxDlg : public CDialog
{
// Construction
public:
	CBaseComboBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBaseComboBoxDlg)
	enum { IDD = IDD_BASECOMBOBOX_DIALOG };
	CComboBox	m_ctlCombo;
	CString	m_edit;
	CString	m_static;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseComboBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBaseComboBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASECOMBOBOXDLG_H__A0E51BAE_5665_4816_A183_AE9693038F6B__INCLUDED_)
