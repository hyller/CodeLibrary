// MessageBoxDemoDlg.h : header file
//

#if !defined(AFX_MESSAGEBOXDEMODLG_H__B43FF1E8_5E12_4265_8653_0195F7FD261A__INCLUDED_)
#define AFX_MESSAGEBOXDEMODLG_H__B43FF1E8_5E12_4265_8653_0195F7FD261A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMessageBoxDemoDlg dialog

class CMessageBoxDemoDlg : public CDialog
{
// Construction
public:
	CMessageBoxDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMessageBoxDemoDlg)
	enum { IDD = IDD_MESSAGEBOXDEMO_DIALOG };
	CStatic	m_ctlStatic;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMessageBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMessageBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnQuit();
	afx_msg void OnMsg();
	afx_msg void OnError();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGEBOXDEMODLG_H__B43FF1E8_5E12_4265_8653_0195F7FD261A__INCLUDED_)
