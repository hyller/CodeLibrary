// FileDlgDemoDlg.h : header file
//

#if !defined(AFX_FILEDLGDEMODLG_H__55A30583_1BA3_4DC6_BCF2_805C2F3C552A__INCLUDED_)
#define AFX_FILEDLGDEMODLG_H__55A30583_1BA3_4DC6_BCF2_805C2F3C552A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileDlgDemoDlg dialog

class CFileDlgDemoDlg : public CDialog
{
// Construction
public:
	CFileDlgDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileDlgDemoDlg)
	enum { IDD = IDD_FILEDLGDEMO_DIALOG };
	CEdit	m_ctlEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileDlgDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileDlgDemoDlg)
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

#endif // !defined(AFX_FILEDLGDEMODLG_H__55A30583_1BA3_4DC6_BCF2_805C2F3C552A__INCLUDED_)
