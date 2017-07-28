// GetDriverSpaceDlg.h : header file
//

#if !defined(AFX_GetDriverSpaceDLG_H__0AABB793_4ECB_436E_BD09_D6566ED246F2__INCLUDED_)
#define AFX_GetDriverSpaceDLG_H__0AABB793_4ECB_436E_BD09_D6566ED246F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetDriverSpaceDlg dialog

class CGetDriverSpaceDlg : public CDialog
{
// Construction
public:
	CGetDriverSpaceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetDriverSpaceDlg)
	enum { IDD = IDD_GetDriverSpace_DIALOG };
	CComboBox	m_ctlDriver;
	CString	m_TotalBytes;
	CString	m_FreeBytes;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetDriverSpaceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetDriverSpaceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GetDriverSpaceDLG_H__0AABB793_4ECB_436E_BD09_D6566ED246F2__INCLUDED_)
