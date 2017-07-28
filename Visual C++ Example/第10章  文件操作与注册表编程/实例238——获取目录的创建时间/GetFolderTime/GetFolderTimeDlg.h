// GetFolderTimeDlg.h : header file
//

#if !defined(AFX_GETFOLDERTIMEDLG_H__07C84198_DC4D_4EEA_9E97_2DFF3CA4616D__INCLUDED_)
#define AFX_GETFOLDERTIMEDLG_H__07C84198_DC4D_4EEA_9E97_2DFF3CA4616D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetFolderTimeDlg dialog

class CGetFolderTimeDlg : public CDialog
{
// Construction
public:
	CGetFolderTimeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetFolderTimeDlg)
	enum { IDD = IDD_GETFOLDERTIME_DIALOG };
	CString	m_strCreateTime;
	CString	m_strFolder;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetFolderTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetFolderTimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFolder();
	afx_msg void OnGettime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETFOLDERTIMEDLG_H__07C84198_DC4D_4EEA_9E97_2DFF3CA4616D__INCLUDED_)
