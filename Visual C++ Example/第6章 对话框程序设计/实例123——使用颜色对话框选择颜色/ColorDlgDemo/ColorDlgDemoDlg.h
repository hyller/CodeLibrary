// ColorDlgDemoDlg.h : header file
//

#if !defined(AFX_COLORDLGDEMODLG_H__F47D8483_DBF1_4890_857C_D4F1B3DC5585__INCLUDED_)
#define AFX_COLORDLGDEMODLG_H__F47D8483_DBF1_4890_857C_D4F1B3DC5585__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CColorDlgDemoDlg dialog

class CColorDlgDemoDlg : public CDialog
{
// Construction
public:
	CColorDlgDemoDlg(CWnd* pParent = NULL);	// standard constructor
	COLORREF crColor;		//Ìî³äÑÕÉ«
// Dialog Data
	//{{AFX_DATA(CColorDlgDemoDlg)
	enum { IDD = IDD_COLORDLGDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorDlgDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CColorDlgDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORDLGDEMODLG_H__F47D8483_DBF1_4890_857C_D4F1B3DC5585__INCLUDED_)
