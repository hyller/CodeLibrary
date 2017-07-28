// CheckFileDemoDlg.h : header file
//

#if !defined(AFX_CheckFileDemoDLG_H__E4664356_EE14_4443_8D62_4F6F384AF66D__INCLUDED_)
#define AFX_CheckFileDemoDLG_H__E4664356_EE14_4443_8D62_4F6F384AF66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCheckFileDemoDlg dialog

class CCheckFileDemoDlg : public CDialog
{
// Construction
public:
	void FindFile(CString Curdir);
	CCheckFileDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCheckFileDemoDlg)
	enum { IDD = IDD_CheckFileDemo_DIALOG };
	CListBox	m_fileList;
	CString	m_folder;
	int		m_filenum;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckFileDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCheckFileDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSearch();
	afx_msg void OnFolder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CheckFileDemoDLG_H__E4664356_EE14_4443_8D62_4F6F384AF66D__INCLUDED_)
