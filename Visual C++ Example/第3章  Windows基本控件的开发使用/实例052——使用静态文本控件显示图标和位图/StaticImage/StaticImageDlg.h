// StaticImageDlg.h : header file
//

#if !defined(AFX_STATICIMAGEDLG_H__01EBCE26_00CD_480C_BC9D_FA9B6C83B818__INCLUDED_)
#define AFX_STATICIMAGEDLG_H__01EBCE26_00CD_480C_BC9D_FA9B6C83B818__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStaticImageDlg dialog

class CStaticImageDlg : public CDialog
{
// Construction
public:
	CStaticImageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStaticImageDlg)
	enum { IDD = IDD_STATICIMAGE_DIALOG };
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticImageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStaticImageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowbitmap();
	afx_msg void OnShowicon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICIMAGEDLG_H__01EBCE26_00CD_480C_BC9D_FA9B6C83B818__INCLUDED_)
