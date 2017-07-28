// ReceiveMessageFromProDlg.h : header file
//

#if !defined(AFX_RECEIVEMESSAGEFROMPRODLG_H__A6A2E181_A5BA_42C9_98D5_8112D1DE64FB__INCLUDED_)
#define AFX_RECEIVEMESSAGEFROMPRODLG_H__A6A2E181_A5BA_42C9_98D5_8112D1DE64FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReceiveMessageFromProDlg dialog

class CReceiveMessageFromProDlg : public CDialog
{
// Construction
public:
	CReceiveMessageFromProDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReceiveMessageFromProDlg)
	enum { IDD = IDD_RECEIVEMESSAGEFROMPRO_DIALOG };
	CString	m_strMessage;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReceiveMessageFromProDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReceiveMessageFromProDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	void OnReceiveMsg(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECEIVEMESSAGEFROMPRODLG_H__A6A2E181_A5BA_42C9_98D5_8112D1DE64FB__INCLUDED_)
