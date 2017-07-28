// SortDemoDlg.h : header file
//

#if !defined(AFX_SORTDEMODLG_H__462FC6E2_2241_4CD7_A1FE_2B814F2E620F__INCLUDED_)
#define AFX_SORTDEMODLG_H__462FC6E2_2241_4CD7_A1FE_2B814F2E620F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSortDemoDlg dialog

class CSortDemoDlg : public CDialog
{
// Construction
public:
	CSortDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSortDemoDlg)
	enum { IDD = IDD_SORTDEMO_DIALOG };
	int		m_nSize;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSortDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartsort();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void GetElements(CString str,int nSize,CStringArray& list);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTDEMODLG_H__462FC6E2_2241_4CD7_A1FE_2B814F2E620F__INCLUDED_)
