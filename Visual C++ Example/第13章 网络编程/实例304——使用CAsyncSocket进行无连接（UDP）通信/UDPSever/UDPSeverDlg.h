// UDPSeverDlg.h : header file
//

#if !defined(AFX_UDPSeverDLG_H__6B8C2C91_5D81_4946_9545_53D4B1895B67__INCLUDED_)
#define AFX_UDPSeverDLG_H__6B8C2C91_5D81_4946_9545_53D4B1895B67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUDPSeverDlg dialog

class CUDPSeverDlg : public CDialog
{
// Construction
public:
	CUDPSeverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUDPSeverDlg)
	enum { IDD = IDD_UDPSever_DIALOG };
	CString	m_ServerIP;
	int		m_ServerPort;
	CString	m_ClientIP;
	int		m_ClientPort;
	int		m_sendcount;
	CString	m_strSend;
	//}}AFX_DATA
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPSeverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CAsyncSocket m_sockSend;									//声明一个Socket对象
	// Generated message map functions
	//{{AFX_MSG(CUDPSeverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPSeverDLG_H__6B8C2C91_5D81_4946_9545_53D4B1895B67__INCLUDED_)
