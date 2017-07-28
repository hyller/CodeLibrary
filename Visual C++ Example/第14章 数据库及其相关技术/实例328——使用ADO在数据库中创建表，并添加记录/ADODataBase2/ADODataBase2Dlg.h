// ADODataBase2Dlg.h : header file
//

#if !defined(AFX_ADODataBase2DLG_H__C350EC08_C082_4B6B_8561_C295B04DB14B__INCLUDED_)
#define AFX_ADODataBase2DLG_H__C350EC08_C082_4B6B_8561_C295B04DB14B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADODataBase2Dlg dialog

class CADODataBase2Dlg : public CDialog
{
// Construction
public:
	CADODataBase2Dlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;									//连接对象指针
// Dialog Data
	//{{AFX_DATA(CADODataBase2Dlg)
	enum { IDD = IDD_ADODataBase2_DIALOG };
	CString	m_strNumber;
	CString	m_strName;
	CString	m_strSex;
	CString	m_strAddress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODataBase2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CADODataBase2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODataBase2DLG_H__C350EC08_C082_4B6B_8561_C295B04DB14B__INCLUDED_)
