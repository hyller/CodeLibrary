// StarOtherProDlg.h : header file
//

#if !defined(AFX_STAROTHERPRODLG_H__35B4FF34_D649_47C6_8D22_1377B2C1A69F__INCLUDED_)
#define AFX_STAROTHERPRODLG_H__35B4FF34_D649_47C6_8D22_1377B2C1A69F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStarOtherProDlg dialog

class CStarOtherProDlg : public CDialog
{
// Construction
public:
	CStarOtherProDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStarOtherProDlg)
	enum { IDD = IDD_STAROTHERPRO_DIALOG };
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStarOtherProDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStarOtherProDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STAROTHERPRODLG_H__35B4FF34_D649_47C6_8D22_1377B2C1A69F__INCLUDED_)
