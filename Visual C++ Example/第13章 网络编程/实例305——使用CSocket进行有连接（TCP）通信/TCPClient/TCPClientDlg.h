// TCPClientDlg.h : header file
//

#if !defined(AFX_TCPClientDLG_H__CC6E3F32_8E38_4608_89FA_5B7727D87B91__INCLUDED_)
#define AFX_TCPClientDLG_H__CC6E3F32_8E38_4608_89FA_5B7727D87B91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTCPClientDlg dialog

class CTCPClientDlg : public CDialog
{
// Construction
public:
	CTCPClientDlg(CWnd* pParent = NULL);	// standard constructor
	CSocket m_sockReceive;								//声明一个Socket对象
// Dialog Data
	//{{AFX_DATA(CTCPClientDlg)
	enum { IDD = IDD_TCPClient_DIALOG };
	CString	m_ServerIP;
	int		m_ServerPort;
	CString	m_ReceiveData;
	int		m_receivecount;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReceive();
	afx_msg void OnStop();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPClientDLG_H__CC6E3F32_8E38_4608_89FA_5B7727D87B91__INCLUDED_)
