// CheckDragListBoxDlg.h : header file
//

#if !defined(AFX_CHECKDRAGLISTBOXDLG_H__E5D11F67_8D19_4FF8_AD81_5182712A28F5__INCLUDED_)
#define AFX_CHECKDRAGLISTBOXDLG_H__E5D11F67_8D19_4FF8_AD81_5182712A28F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCheckDragListBoxDlg dialog

class CCheckDragListBoxDlg : public CDialog
{
// Construction
public:
	CCheckDragListBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCheckDragListBoxDlg)
	enum { IDD = IDD_CHECKDRAGLISTBOX_DIALOG };
	CDragListBox	m_ctlDraglist;
	CCheckListBox	m_ctlChecklist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckDragListBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCheckDragListBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKDRAGLISTBOXDLG_H__E5D11F67_8D19_4FF8_AD81_5182712A28F5__INCLUDED_)
