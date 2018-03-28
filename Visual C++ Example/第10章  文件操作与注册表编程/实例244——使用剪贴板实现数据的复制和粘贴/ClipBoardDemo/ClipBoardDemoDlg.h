// ClipBoardDemoDlg.h : header file
//

#if !defined(AFX_ClipBoardDemoDLG_H__386725AA_5FD9_45AA_94A8_75B81C0D4EDE__INCLUDED_)
#define AFX_ClipBoardDemoDLG_H__386725AA_5FD9_45AA_94A8_75B81C0D4EDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClipBoardDemoDlg dialog

class CClipBoardDemoDlg : public CDialog
{
// Construction
public:
	CClipBoardDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClipBoardDemoDlg)
	enum { IDD = IDD_ClipBoardDemo_DIALOG };
	CListBox	m_booklist2;
	CListBox	m_booklist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipBoardDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClipBoardDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCopy();
	afx_msg void OnPlaste();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ClipBoardDemoDLG_H__386725AA_5FD9_45AA_94A8_75B81C0D4EDE__INCLUDED_)
