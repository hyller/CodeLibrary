// SendNotepadMsgDlg.h : header file
//

#if !defined(AFX_SENDNOTEPADMSGDLG_H__3E8AF5A1_968B_49AE_9A02_07F4626360AF__INCLUDED_)
#define AFX_SENDNOTEPADMSGDLG_H__3E8AF5A1_968B_49AE_9A02_07F4626360AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSendNotepadMsgDlg dialog

class CSendNotepadMsgDlg : public CDialog
{
// Construction
public:
	CSendNotepadMsgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSendNotepadMsgDlg)
	enum { IDD = IDD_SENDNOTEPADMSG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendNotepadMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSendNotepadMsgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDNOTEPADMSGDLG_H__3E8AF5A1_968B_49AE_9A02_07F4626360AF__INCLUDED_)
