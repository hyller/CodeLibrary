// TransClientDlg.h : header file
//

#if !defined(AFX_TransClientDLG_H__070418BA_B858_4BA7_9147_C48532BA22F8__INCLUDED_)
#define AFX_TransClientDLG_H__070418BA_B858_4BA7_9147_C48532BA22F8__INCLUDED_
#include "ClientSocket.h"
#include "AddrDlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTransClientDlg dialog

class CTransClientDlg : public CDialog
{
// Construction
public:
	CTransClientDlg(CWnd* pParent = NULL);	// standard constructor
	char m_szServerAdr[256];//IP地址
// Dialog Data
	//{{AFX_DATA(CTransClientDlg)
	enum { IDD = IDD_TransClient_DIALOG };
	CListBox	m_MsgR;
	CEdit	m_MsgS;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int TryCount;//最大连接次数
	CClientSocket m_clientSocket;
	UINT m_szPort;//端口
	// Generated message map functions
	//{{AFX_MSG(CTransClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnClose();
	afx_msg void OnSend();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TransClientDLG_H__070418BA_B858_4BA7_9147_C48532BA22F8__INCLUDED_)
