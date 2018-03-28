// ChangeSizeDlgDlg.h : header file
//

#if !defined(AFX_CHANGESIZEDLGDLG_H__4480DF02_2255_49AD_A61F_A759C691194B__INCLUDED_)
#define AFX_CHANGESIZEDLGDLG_H__4480DF02_2255_49AD_A61F_A759C691194B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChangeSizeDlgDlg dialog

class CChangeSizeDlgDlg : public CDialog
{
// Construction
public:
	CChangeSizeDlgDlg(CWnd* pParent = NULL);	// standard constructor
	bool pSize;
	CRect pFull;//大尺寸对话框区域
	CRect pHalf;//小尺寸对话框区域
// Dialog Data
	//{{AFX_DATA(CChangeSizeDlgDlg)
	enum { IDD = IDD_CHANGESIZEDLG_DIALOG };
	CButton	m_ctlMorebutton;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeSizeDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	void ChangeDlgSize();
	// Generated message map functions
	//{{AFX_MSG(CChangeSizeDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGESIZEDLGDLG_H__4480DF02_2255_49AD_A61F_A759C691194B__INCLUDED_)
