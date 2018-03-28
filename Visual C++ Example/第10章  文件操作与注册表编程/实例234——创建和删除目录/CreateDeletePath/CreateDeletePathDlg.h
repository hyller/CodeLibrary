// CreateDeletePathDlg.h : header file
//

#if !defined(AFX_CREATEDELETEPATHDLG_H__FE01F1BF_7321_40C2_BEAD_62A5097ADB87__INCLUDED_)
#define AFX_CREATEDELETEPATHDLG_H__FE01F1BF_7321_40C2_BEAD_62A5097ADB87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateDeletePathDlg dialog

class CCreateDeletePathDlg : public CDialog
{
// Construction
public:
	CCreateDeletePathDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateDeletePathDlg)
	enum { IDD = IDD_CREATEDELETEPATH_DIALOG };
	CString	m_strPath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateDeletePathDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateDeletePathDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDelete();
	afx_msg void OnCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEDELETEPATHDLG_H__FE01F1BF_7321_40C2_BEAD_62A5097ADB87__INCLUDED_)
