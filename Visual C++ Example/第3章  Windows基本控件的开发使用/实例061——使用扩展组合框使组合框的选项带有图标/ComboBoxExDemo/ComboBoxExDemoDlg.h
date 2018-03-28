// ComboBoxExDemoDlg.h : header file
//

#if !defined(AFX_COMBOBOXEXDEMODLG_H__A106FD7B_41A2_46CB_8933_0E9785C3D606__INCLUDED_)
#define AFX_COMBOBOXEXDEMODLG_H__A106FD7B_41A2_46CB_8933_0E9785C3D606__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CComboBoxExDemoDlg dialog

class CComboBoxExDemoDlg : public CDialog
{
// Construction
public:
	CComboBoxExDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CComboBoxExDemoDlg)
	enum { IDD = IDD_COMBOBOXEXDEMO_DIALOG };
	CComboBoxEx	m_ctlComboEx;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboBoxExDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CImageList m_pImageList;//图像列表对象

	// Generated message map functions
	//{{AFX_MSG(CComboBoxExDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOBOXEXDEMODLG_H__A106FD7B_41A2_46CB_8933_0E9785C3D606__INCLUDED_)
