// PPServerDlg.h : header file
//

#if !defined(AFX_PPServerDLG_H__419C963A_D1F4_4C08_BE95_DF225AA950CA__INCLUDED_)
#define AFX_PPServerDLG_H__419C963A_D1F4_4C08_BE95_DF225AA950CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "winsock2.h"
#define CONNECE_PORT 8080     //定义通信端口
#define TIME_OUT     30       //定义超时时限

/////////////////////////////////////////////////////////////////////////////
// CPPServerDlg dialog

class CPPServerDlg : public CDialog
{
// Construction
public:
	CPPServerDlg(CWnd* pParent = NULL);	// standard constructor
	void SendMsg(SOCKET socket,LPCTSTR sBuff);

// Dialog Data
	//{{AFX_DATA(CPPServerDlg)
	enum { IDD = IDD_PPServer_DIALOG };
	CString	m_strMsg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPPServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnEnd();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPServerDLG_H__419C963A_D1F4_4C08_BE95_DF225AA950CA__INCLUDED_)
