// ActiveXAutoRegDlg.h : header file
//

#if !defined(AFX_ActiveXAutoRegDLG_H__F12FE9ED_A5B6_412D_A938_AB0C180E3C34__INCLUDED_)
#define AFX_ActiveXAutoRegDLG_H__F12FE9ED_A5B6_412D_A938_AB0C180E3C34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CActiveXAutoRegDlg dialog

class CActiveXAutoRegDlg : public CDialog
{
// Construction
public:
	CActiveXAutoRegDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CActiveXAutoRegDlg)
	enum { IDD = IDD_ActiveXAutoReg_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CActiveXAutoRegDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CActiveXAutoRegDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRegister();
	afx_msg void OnUnregister();
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ActiveXAutoRegDLG_H__F12FE9ED_A5B6_412D_A938_AB0C180E3C34__INCLUDED_)
