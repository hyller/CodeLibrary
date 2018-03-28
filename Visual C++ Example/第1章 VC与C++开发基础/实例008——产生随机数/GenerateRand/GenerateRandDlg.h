// GenerateRandDlg.h : header file
//

#if !defined(AFX_GENERATERANDDLG_H__323126CD_2F48_4BC1_B5D9_6CF197024CD9__INCLUDED_)
#define AFX_GENERATERANDDLG_H__323126CD_2F48_4BC1_B5D9_6CF197024CD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGenerateRandDlg dialog

class CGenerateRandDlg : public CDialog
{
// Construction
public:
	CGenerateRandDlg(CWnd* pParent = NULL);	// standard constructor
	double GetRand(double MIN, double MAX);
// Dialog Data
	//{{AFX_DATA(CGenerateRandDlg)
	enum { IDD = IDD_GENERATERAND_DIALOG };
	double	m_Min;
	double	m_Max;
	double	m_Rand1;
	double	m_Rand2;
	double	m_Rand3;
	double	m_Rand4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenerateRandDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGenerateRandDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGenerate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERATERANDDLG_H__323126CD_2F48_4BC1_B5D9_6CF197024CD9__INCLUDED_)
