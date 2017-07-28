// ADODataBase1Dlg.h : header file
//

#if !defined(AFX_ADODATABASE1DLG_H__C350EC08_C082_4B6B_8561_C295B04DB14B__INCLUDED_)
#define AFX_ADODATABASE1DLG_H__C350EC08_C082_4B6B_8561_C295B04DB14B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADODataBase1Dlg dialog

class CADODataBase1Dlg : public CDialog
{
// Construction
public:
	CADODataBase1Dlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;									//连接对象指针
// Dialog Data
	//{{AFX_DATA(CADODataBase1Dlg)
	enum { IDD = IDD_ADODATABASE1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODataBase1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CADODataBase1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATABASE1DLG_H__C350EC08_C082_4B6B_8561_C295B04DB14B__INCLUDED_)
