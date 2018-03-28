// EnumDeviceInfoDlg.h : header file
//

#if !defined(AFX_ENUMDEVICEINFODLG_H__8A21058A_3234_47AD_A052_DFAE9049AC73__INCLUDED_)
#define AFX_ENUMDEVICEINFODLG_H__8A21058A_3234_47AD_A052_DFAE9049AC73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEnumDeviceInfoDlg dialog

class CEnumDeviceInfoDlg : public CDialog
{
// Construction
public:
	CEnumDeviceInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEnumDeviceInfoDlg)
	enum { IDD = IDD_ENUMDEVICEINFO_DIALOG };
	CListBox	m_ctlList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumDeviceInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEnumDeviceInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetdevice();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMDEVICEINFODLG_H__8A21058A_3234_47AD_A052_DFAE9049AC73__INCLUDED_)
