// MergFileDemoDlg.h : header file
//

#if !defined(AFX_MERGFILEDEMODLG_H__F9A37A80_F324_408B_A541_15AE8ABEBF02__INCLUDED_)
#define AFX_MERGFILEDEMODLG_H__F9A37A80_F324_408B_A541_15AE8ABEBF02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMergFileDemoDlg dialog

class CMergFileDemoDlg : public CDialog
{
// Construction
public:
	CMergFileDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMergFileDemoDlg)
	enum { IDD = IDD_MERGFILEDEMO_DIALOG };
	CString	m_strpath;
	CString	m_strfile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMergFileDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMergFileDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFile();
	afx_msg void OnMerg();
	afx_msg void OnPath();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MERGFILEDEMODLG_H__F9A37A80_F324_408B_A541_15AE8ABEBF02__INCLUDED_)
