// DlgKeyMessageDlg.h : header file
//

#if !defined(AFX_DLGKEYMESSAGEDLG_H__6C4A7CC5_103F_47BA_A515_A6CD2BE7922A__INCLUDED_)
#define AFX_DLGKEYMESSAGEDLG_H__6C4A7CC5_103F_47BA_A515_A6CD2BE7922A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgKeyMessageDlg dialog

class CDlgKeyMessageDlg : public CDialog
{
// Construction
public:
	CDlgKeyMessageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgKeyMessageDlg)
	enum { IDD = IDD_DLGKEYMESSAGE_DIALOG };
	CStatic	m_ctlframe;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgKeyMessageDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgKeyMessageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGKEYMESSAGEDLG_H__6C4A7CC5_103F_47BA_A515_A6CD2BE7922A__INCLUDED_)
