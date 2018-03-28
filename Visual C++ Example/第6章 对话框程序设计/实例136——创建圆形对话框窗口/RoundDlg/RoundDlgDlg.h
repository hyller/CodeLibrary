// RoundDlgDlg.h : header file
//

#if !defined(AFX_ROUNDDLGDLG_H__BA238C35_A09C_4C2B_AEFF_069046CB2E43__INCLUDED_)
#define AFX_ROUNDDLGDLG_H__BA238C35_A09C_4C2B_AEFF_069046CB2E43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRoundDlgDlg dialog

class CRoundDlgDlg : public CDialog
{
// Construction
public:
	CRoundDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRoundDlgDlg)
	enum { IDD = IDD_ROUNDDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoundDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CRgn m_rgn; //«¯”Ú∂‘œÛ
	// Generated message map functions
	//{{AFX_MSG(CRoundDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROUNDDLGDLG_H__BA238C35_A09C_4C2B_AEFF_069046CB2E43__INCLUDED_)
