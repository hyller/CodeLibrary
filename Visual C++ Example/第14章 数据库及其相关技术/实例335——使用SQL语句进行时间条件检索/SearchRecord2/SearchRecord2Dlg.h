// SearchRecord2Dlg.h : header file
//

#if !defined(AFX_SearchRecord2DLG_H__ABFFE4BC_A4A5_4329_B920_DFEECB6FBE5D__INCLUDED_)
#define AFX_SearchRecord2DLG_H__ABFFE4BC_A4A5_4329_B920_DFEECB6FBE5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSearchRecord2Dlg dialog

class CSearchRecord2Dlg : public CDialog
{
// Construction
public:
	CSearchRecord2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchRecord2Dlg)
	enum { IDD = IDD_SearchRecord2_DIALOG };
	CListBox	m_ctlList;
	CTime	m_tmBegin;
	CTime	m_tmEnd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchRecord2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	_ConnectionPtr m_pCon;		//连接对象
	_RecordsetPtr m_pRs;		//记录集对象
	// Generated message map functions
	//{{AFX_MSG(CSearchRecord2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSearch();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SearchRecord2DLG_H__ABFFE4BC_A4A5_4329_B920_DFEECB6FBE5D__INCLUDED_)
