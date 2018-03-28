// ClipTextTransDlg.h : header file
//

#if !defined(AFX_CLIPTEXTTRANSDLG_H__E84D993B_C54B_410B_BBCC_15F4B10F9C6C__INCLUDED_)
#define AFX_CLIPTEXTTRANSDLG_H__E84D993B_C54B_410B_BBCC_15F4B10F9C6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClipTextTransDlg dialog

class CClipTextTransDlg : public CDialog
{
// Construction
public:
	CClipTextTransDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClipTextTransDlg)
	enum { IDD = IDD_CLIPTEXTTRANS_DIALOG };
	CString	m_strSource;
	CString	m_strDest;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipTextTransDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClipTextTransDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCopy();
	afx_msg void OnCut();
	afx_msg void OnPlaste();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPTEXTTRANSDLG_H__E84D993B_C54B_410B_BBCC_15F4B10F9C6C__INCLUDED_)
