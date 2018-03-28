// ADOTranDlg.h : header file
//

#if !defined(AFX_ADOTRANDLG_H__A0FDF995_6C4E_4F06_82B1_FC78BA9F2A54__INCLUDED_)
#define AFX_ADOTRANDLG_H__A0FDF995_6C4E_4F06_82B1_FC78BA9F2A54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADOTranDlg dialog

class CADOTranDlg : public CDialog
{
// Construction
public:
	CADOTranDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CADOTranDlg)
	enum { IDD = IDD_ADOTRAN_DIALOG };
	CListBox	m_ctlList;
	CString	m_CNO;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOTranDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CADOTranDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOTRANDLG_H__A0FDF995_6C4E_4F06_82B1_FC78BA9F2A54__INCLUDED_)
