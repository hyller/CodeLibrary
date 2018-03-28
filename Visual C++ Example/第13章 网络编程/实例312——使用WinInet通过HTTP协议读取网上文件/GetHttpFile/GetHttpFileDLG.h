// GetHttpFileDlg.h : header file
//

#if !defined(AFX_GetHttpFileDLG_H__70D29E5F_C6F9_47E9_8949_76230547C028__INCLUDED_)
#define AFX_GetHttpFileDLG_H__70D29E5F_C6F9_47E9_8949_76230547C028__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetHttpFileDlg dialog

class CGetHttpFileDlg : public CDialog
{
// Construction
public:
	CGetHttpFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetHttpFileDlg)
	enum { IDD = IDD_GetHttpFile_DIALOG };
	CString	m_Url;
	CString	m_Text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetHttpFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetHttpFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeEdit1();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GetHttpFileDLG_H__70D29E5F_C6F9_47E9_8949_76230547C028__INCLUDED_)
