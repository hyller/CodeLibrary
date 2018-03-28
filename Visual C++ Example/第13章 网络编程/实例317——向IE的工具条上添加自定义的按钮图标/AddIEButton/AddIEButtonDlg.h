// AddIEButtonDlg.h : header file
//

#if !defined(AFX_ADDIEBUTTONDLG_H__ED332690_5AC4_44E5_85B9_FDD4975932D7__INCLUDED_)
#define AFX_ADDIEBUTTONDLG_H__ED332690_5AC4_44E5_85B9_FDD4975932D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAddIEButtonDlg dialog

class CAddIEButtonDlg : public CDialog
{
// Construction
public:
	CAddIEButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAddIEButtonDlg)
	enum { IDD = IDD_ADDIEBUTTON_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddIEButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAddIEButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddicon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDIEBUTTONDLG_H__ED332690_5AC4_44E5_85B9_FDD4975932D7__INCLUDED_)
