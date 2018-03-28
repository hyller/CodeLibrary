// BaseRichEditDlg.h : header file
//

#if !defined(AFX_BASERICHEDITDLG_H__7CB4E992_ACB2_4FE6_B06B_DDCC0B4126B1__INCLUDED_)
#define AFX_BASERICHEDITDLG_H__7CB4E992_ACB2_4FE6_B06B_DDCC0B4126B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBaseRichEditDlg dialog

class CBaseRichEditDlg : public CDialog
{
// Construction
public:
	CBaseRichEditDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CBaseRichEditDlg)
	enum { IDD = IDD_BASERICHEDIT_DIALOG };
	CComboBox	m_ctlPointbox;
	CButton	m_ctlUnderline;
	CButton	m_ctlItalic;
	CButton	m_ctlBold;
	CRichEditCtrl	m_RichSample;
	BOOL	m_bold;
	BOOL	m_italic;
	BOOL	m_underline;
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseRichEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBaseRichEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBold();
	afx_msg void OnItalic();
	afx_msg void OnUnderline();
	afx_msg void OnLett();
	afx_msg void OnRight();
	afx_msg void OnCenter();
	afx_msg void OnSelchangePointbox();
	afx_msg void OnTextColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASERICHEDITDLG_H__7CB4E992_ACB2_4FE6_B06B_DDCC0B4126B1__INCLUDED_)
