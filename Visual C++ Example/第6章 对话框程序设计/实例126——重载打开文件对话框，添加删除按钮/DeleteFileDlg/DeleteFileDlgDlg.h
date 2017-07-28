// DeleteFileDlgDlg.h : header file
//

#if !defined(AFX_DELETEFILEDLGDLG_H__FB4D5D28_D565_4EAB_A4E1_8EC82D98DE43__INCLUDED_)
#define AFX_DELETEFILEDLGDLG_H__FB4D5D28_D565_4EAB_A4E1_8EC82D98DE43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyFileDialog.h" 
/////////////////////////////////////////////////////////////////////////////
// CDeleteFileDlgDlg dialog

class CDeleteFileDlgDlg : public CDialog
{
// Construction
public:
	CDeleteFileDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteFileDlgDlg)
	enum { IDD = IDD_DELETEFILEDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteFileDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDeleteFileDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEFILEDLGDLG_H__FB4D5D28_D565_4EAB_A4E1_8EC82D98DE43__INCLUDED_)
