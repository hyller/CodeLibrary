// StdioFileDemoDlg.h : header file
//

#if !defined(AFX_StdioFileDemoDLG_H__386725AA_5FD9_45AA_94A8_75B81C0D4EDE__INCLUDED_)
#define AFX_StdioFileDemoDLG_H__386725AA_5FD9_45AA_94A8_75B81C0D4EDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStdioFileDemoDlg dialog

class CStdioFileDemoDlg : public CDialog
{
// Construction
public:
	CStdioFileDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStdioFileDemoDlg)
	enum { IDD = IDD_StdioFileDemo_DIALOG };
	CListBox	m_booklist;
	CString	m_bookname;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStdioFileDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStdioFileDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnLoad();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_StdioFileDemoDLG_H__386725AA_5FD9_45AA_94A8_75B81C0D4EDE__INCLUDED_)
