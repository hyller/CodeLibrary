// CPUInfoDlg.h : header file
//

#if !defined(AFX_CPUINFODLG_H__F467E2CD_2C2B_406B_B05F_C12440F07E53__INCLUDED_)
#define AFX_CPUINFODLG_H__F467E2CD_2C2B_406B_B05F_C12440F07E53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCPUInfoDlg dialog

class CCPUInfoDlg : public CDialog
{
// Construction
public:
	CCPUInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCPUInfoDlg)
	enum { IDD = IDD_CPUINFO_DIALOG };
	CString	m_strProcessorType;
	CString	m_strProcessorNum;
	CString	m_strCPUSpeed;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCPUInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCPUInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetcpuinfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUINFODLG_H__F467E2CD_2C2B_406B_B05F_C12440F07E53__INCLUDED_)
