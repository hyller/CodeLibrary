// PPClientDlg.h : header file
//

#if !defined(AFX_PPClientDLG_H__D73C4199_8B85_4D81_81D4_F3CFE191B562__INCLUDED_)
#define AFX_PPClientDLG_H__D73C4199_8B85_4D81_81D4_F3CFE191B562__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define CONNECE_PORT 8080     //定义通信端口
#define TIME_OUT     60       //定义超时时限

#include "winsock2.h"
/////////////////////////////////////////////////////////////////////////////
// CPPClientDlg dialog

class CPPClientDlg : public CDialog
{
// Construction
public:
	CPPClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPPClientDlg)
	enum { IDD = IDD_PPClient_DIALOG };
	CIPAddressCtrl	m_ctrlServer;
	CString	m_strMsg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPPClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	void CPPClientDlg::ContactServer();

public:
	SOCKET m_hSocket;
	sockaddr_in  m_ServerAddr;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPClientDLG_H__D73C4199_8B85_4D81_81D4_F3CFE191B562__INCLUDED_)
