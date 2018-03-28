// FormatStrDlg.h : header file
//

#if !defined(AFX_FORMATSTRDLG_H__46544F80_AC92_442F_BCE5_1A3A33595B92__INCLUDED_)
#define AFX_FORMATSTRDLG_H__46544F80_AC92_442F_BCE5_1A3A33595B92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFormatStrDlg dialog

class CFormatStrDlg : public CDialog
{
// Construction
public:
	CFormatStrDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFormatStrDlg)
	enum { IDD = IDD_FORMATSTR_DIALOG };
	int		m_radio;
	double	m_doubleValue;
	CString	m_strValue;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormatStrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFormatStrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFormat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMATSTRDLG_H__46544F80_AC92_442F_BCE5_1A3A33595B92__INCLUDED_)
