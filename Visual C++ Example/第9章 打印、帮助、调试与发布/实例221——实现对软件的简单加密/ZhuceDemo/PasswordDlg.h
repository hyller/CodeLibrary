#if !defined(AFX_PASSWORDDLG_H__689EFD72_961D_4F32_B8F5_B5713DF077C1__INCLUDED_)
#define AFX_PASSWORDDLG_H__689EFD72_961D_4F32_B8F5_B5713DF077C1__INCLUDED_



#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PasswordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPasswordDlg dialog

class CPasswordDlg : public CDialog
{
// Construction
public:
	CPasswordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPasswordDlg)
	enum { IDD = IDD_DIALOG1 };
	DWORD	m_usernum;
	DWORD	m_serialnum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPasswordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPasswordDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWORDDLG_H__689EFD72_961D_4F32_B8F5_B5713DF077C1__INCLUDED_)
