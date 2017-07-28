// UDPClientDlg.h : header file
//

#if !defined(AFX_UDPClientDLG_H__167EEEBE_585E_4070_8B9D_158BF6E10D3C__INCLUDED_)
#define AFX_UDPClientDLG_H__167EEEBE_585E_4070_8B9D_158BF6E10D3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUDPClientDlg dialog

class CUDPClientDlg : public CDialog
{
// Construction
public:
	CUDPClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUDPClientDlg)
	enum { IDD = IDD_UDPClient_DIALOG };
	CString	m_ClientIP;
	int		m_ClientPort;
	CString	m_ServerIP;
	UINT		m_ServerPort;
	CString	m_ReceiveData;
	int		m_receivecount;
	//}}AFX_DATA
	CAsyncSocket m_sockReceive;									//声明一个Socket对象
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUDPClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReceive();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPClientDLG_H__167EEEBE_585E_4070_8B9D_158BF6E10D3C__INCLUDED_)
