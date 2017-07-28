// ChatRoomServerDlg.h : header file
//

#if !defined(AFX_CHATROOMSERVERDLG_H__5BE648B6_8A9C_4E90_BF1D_20FE943A525F__INCLUDED_)
#define AFX_CHATROOMSERVERDLG_H__5BE648B6_8A9C_4E90_BF1D_20FE943A525F__INCLUDED_

#include "ClientSocketList.h"	// Added by ClassView
#include "ListenSocket.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChatRoomServerDlg dialog

class CChatRoomServerDlg : public CDialog
{
// Construction
public:
	CListenSocket ListenSocket;
	CChatRoomServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChatRoomServerDlg)
	enum { IDD = IDD_CHATROOMSERVER_DIALOG };
	CButton	m_IDC_BUTTON_STOP;
	CButton	m_IDC_BUTTON_START;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatRoomServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatRoomServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATROOMSERVERDLG_H__5BE648B6_8A9C_4E90_BF1D_20FE943A525F__INCLUDED_)
