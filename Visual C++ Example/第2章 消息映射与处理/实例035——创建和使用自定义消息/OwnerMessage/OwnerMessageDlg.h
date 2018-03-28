// OwnerMessageDlg.h : header file
//

#if !defined(AFX_OWNERMESSAGEDLG_H__5AA8FB8C_9132_4577_B3D4_3EB7C462DC6C__INCLUDED_)
#define AFX_OWNERMESSAGEDLG_H__5AA8FB8C_9132_4577_B3D4_3EB7C462DC6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COwnerMessageDlg dialog
class COwnerMessageDlg : public CDialog
{
// Construction
public:
	COwnerMessageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COwnerMessageDlg)
	enum { IDD = IDD_OWNERMESSAGE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COwnerMessageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COwnerMessageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg LRESULT OnMyMessage(WPARAM w,LPARAM l); //添加消息响应函数

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OWNERMESSAGEDLG_H__5AA8FB8C_9132_4577_B3D4_3EB7C462DC6C__INCLUDED_)
