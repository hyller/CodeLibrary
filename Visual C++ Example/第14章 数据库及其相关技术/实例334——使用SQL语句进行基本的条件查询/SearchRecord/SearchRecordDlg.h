// SearchRecordDlg.h : header file
//

#if !defined(AFX_SEARCHRECORDDLG_H__ABFFE4BC_A4A5_4329_B920_DFEECB6FBE5D__INCLUDED_)
#define AFX_SEARCHRECORDDLG_H__ABFFE4BC_A4A5_4329_B920_DFEECB6FBE5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSearchRecordDlg dialog

class CSearchRecordDlg : public CDialog
{
// Construction
public:
	CSearchRecordDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchRecordDlg)
	enum { IDD = IDD_SEARCHRECORD_DIALOG };
	CListBox	m_ctlList;
	CString	m_strSex;
	CString	m_strHome;
	BOOL	m_bFullMatch;
	BOOL	m_bAnd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	_ConnectionPtr m_pCon;		//连接对象
	_RecordsetPtr m_pRs;		//记录集对象
	// Generated message map functions
	//{{AFX_MSG(CSearchRecordDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHRECORDDLG_H__ABFFE4BC_A4A5_4329_B920_DFEECB6FBE5D__INCLUDED_)
