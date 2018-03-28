// AnimationDemoDlg.h : header file
//

#if !defined(AFX_ANIMATIONDEMODLG_H__9B9A94F7_A05C_4E25_BF8F_82B36A33DFA9__INCLUDED_)
#define AFX_ANIMATIONDEMODLG_H__9B9A94F7_A05C_4E25_BF8F_82B36A33DFA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAnimationDemoDlg dialog

class CAnimationDemoDlg : public CDialog
{
// Construction
public:
	CAnimationDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAnimationDemoDlg)
	enum { IDD = IDD_ANIMATIONDEMO_DIALOG };
	CAnimateCtrl	m_ctlAnimate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimationDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAnimationDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPause();
	afx_msg void OnPlay();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATIONDEMODLG_H__9B9A94F7_A05C_4E25_BF8F_82B36A33DFA9__INCLUDED_)
