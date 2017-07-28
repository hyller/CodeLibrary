// MultiFileDlgDemoDlg.h : header file
//

#if !defined(AFX_MULTIFILEDLGDEMODLG_H__0E62ABF2_6343_4C7B_BE98_0F641A0AC08A__INCLUDED_)
#define AFX_MULTIFILEDLGDEMODLG_H__0E62ABF2_6343_4C7B_BE98_0F641A0AC08A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiFileDlgDemoDlg dialog

class CMultiFileDlgDemoDlg : public CDialog
{
// Construction
public:
	CMultiFileDlgDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiFileDlgDemoDlg)
	enum { IDD = IDD_MULTIFILEDLGDEMO_DIALOG };
	CListBox	m_ctlList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiFileDlgDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiFileDlgDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileopen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIFILEDLGDEMODLG_H__0E62ABF2_6343_4C7B_BE98_0F641A0AC08A__INCLUDED_)
