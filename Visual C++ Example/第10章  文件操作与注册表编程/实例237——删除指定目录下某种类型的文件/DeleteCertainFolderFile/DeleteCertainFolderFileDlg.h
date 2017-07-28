// DeleteCertainFolderFileDlg.h : header file
//

#if !defined(AFX_DELETECERTAINFOLDERFILEDLG_H__EEECFBDF_58FB_44FA_B4E5_7689F766AB7B__INCLUDED_)
#define AFX_DELETECERTAINFOLDERFILEDLG_H__EEECFBDF_58FB_44FA_B4E5_7689F766AB7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDeleteCertainFolderFileDlg dialog

class CDeleteCertainFolderFileDlg : public CDialog
{
// Construction
public:
	CDeleteCertainFolderFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteCertainFolderFileDlg)
	enum { IDD = IDD_DELETECERTAINFOLDERFILE_DIALOG };
	CString	m_strFolder;
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteCertainFolderFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	void DisplayFileList(CString strdir);
	// Generated message map functions
	//{{AFX_MSG(CDeleteCertainFolderFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFolder();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnDelete();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETECERTAINFOLDERFILEDLG_H__EEECFBDF_58FB_44FA_B4E5_7689F766AB7B__INCLUDED_)
