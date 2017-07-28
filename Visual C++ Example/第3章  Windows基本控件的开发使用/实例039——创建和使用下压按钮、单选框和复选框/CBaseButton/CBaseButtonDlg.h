// CBaseButtonDlg.h : header file
//

#if !defined(AFX_CBASEBUTTONDLG_H__FD9D0220_5062_4F8F_98F8_82A8AB1E9EB7__INCLUDED_)
#define AFX_CBASEBUTTONDLG_H__FD9D0220_5062_4F8F_98F8_82A8AB1E9EB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCBaseButtonDlg dialog

class CCBaseButtonDlg : public CDialog
{
// Construction
public:
	CCBaseButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCBaseButtonDlg)
	enum { IDD = IDD_CBASEBUTTON_DIALOG };
	CButton	m_check4;
	CButton	m_check3;
	CButton	m_check2;
	CButton	m_check1;
	int		m_radio;
	CString	m_show;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCBaseButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCBaseButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheckin();
	afx_msg void OnReset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CBASEBUTTONDLG_H__FD9D0220_5062_4F8F_98F8_82A8AB1E9EB7__INCLUDED_)
