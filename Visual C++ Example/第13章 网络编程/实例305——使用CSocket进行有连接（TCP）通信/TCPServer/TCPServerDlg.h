// TCPServerDlg.h : header file
//

#if !defined(AFX_TCPServerDLG_H__0636A29E_A34E_453C_AA5B_C6CED2CD17A7__INCLUDED_)
#define AFX_TCPServerDLG_H__0636A29E_A34E_453C_AA5B_C6CED2CD17A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTCPServerDlg dialog

class CTCPServerDlg : public CDialog
{
// Construction
public:
	CTCPServerDlg(CWnd* pParent = NULL);	// standard constructor
	CSocket m_sockListen;					//声明一个监听套接字
	CAsyncSocket m_sockSend;					//声明一个发送套接字
// Dialog Data
	//{{AFX_DATA(CTCPServerDlg)
	enum { IDD = IDD_TCPServer_DIALOG };
	CString	m_ServerIP;
	int		m_ServerPort;
	CString	m_ServerStatus;
	int		m_sendcount;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnStop();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPServerDLG_H__0636A29E_A34E_453C_AA5B_C6CED2CD17A7__INCLUDED_)
