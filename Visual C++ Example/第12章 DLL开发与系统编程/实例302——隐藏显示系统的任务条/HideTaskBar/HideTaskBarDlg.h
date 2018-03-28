// HideTaskBarDlg.h : header file
//

#if !defined(AFX_HIDETASKBARDLG_H__EDDA75DE_1929_4495_A460_FE0701C6BAAF__INCLUDED_)
#define AFX_HIDETASKBARDLG_H__EDDA75DE_1929_4495_A460_FE0701C6BAAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHideTaskBarDlg dialog

class CHideTaskBarDlg : public CDialog
{
// Construction
public:
	CHideTaskBarDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHideTaskBarDlg)
	enum { IDD = IDD_HIDETASKBAR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideTaskBarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	BOOL Flag;
	// Generated message map functions
	//{{AFX_MSG(CHideTaskBarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHideshow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDETASKBARDLG_H__EDDA75DE_1929_4495_A460_FE0701C6BAAF__INCLUDED_)
