// DialogEditDragDlg.h : header file
//

#if !defined(AFX_DIALOGEDITDRAGDLG_H__8A1081C0_CE6B_4126_BD84_182FE4668D6F__INCLUDED_)
#define AFX_DIALOGEDITDRAGDLG_H__8A1081C0_CE6B_4126_BD84_182FE4668D6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DragEdit.h"
/////////////////////////////////////////////////////////////////////////////
// CDialogEditDragDlg dialog

class CDialogEditDragDlg : public CDialog
{
// Construction
public:
	CDialogEditDragDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogEditDragDlg)
	enum { IDD = IDD_DIALOGEDITDRAG_DIALOG };
	CDragEdit	m_ctlEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogEditDragDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDialogEditDragDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGEDITDRAGDLG_H__8A1081C0_CE6B_4126_BD84_182FE4668D6F__INCLUDED_)
