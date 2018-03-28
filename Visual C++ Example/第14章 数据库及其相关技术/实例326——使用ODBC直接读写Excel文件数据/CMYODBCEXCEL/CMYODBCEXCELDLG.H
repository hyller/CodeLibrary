// CMyOdbcExcelDlg.h : header file
//

#if !defined(AFX_CMYODBCEXCELDLG_H__1F64B096_73B1_4518_B4CD_A35BCCD5ABA1__INCLUDED_)
#define AFX_CMYODBCEXCELDLG_H__1F64B096_73B1_4518_B4CD_A35BCCD5ABA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCMyOdbcExcelDlg dialog

class CCMyOdbcExcelDlg : public CDialog
{
// Construction
public:
	CString GetExcelDriver();
	CCMyOdbcExcelDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCMyOdbcExcelDlg)
	enum { IDD = IDD_CMYODBCEXCEL_DIALOG };
	CListBox	m_nExcelList;
	CButton	m_nWrite;
	CButton	m_nRead;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMyOdbcExcelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCMyOdbcExcelDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonRead();
	afx_msg void OnButtonWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMYODBCEXCELDLG_H__1F64B096_73B1_4518_B4CD_A35BCCD5ABA1__INCLUDED_)
