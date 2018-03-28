#if !defined(AFX_DlgDocFrameDLG_H__AA13F6BF_6E7C_4A68_9346_7094E9090CDD__INCLUDED_)
#define AFX_DlgDocFrameDLG_H__AA13F6BF_6E7C_4A68_9346_7094E9090CDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDocFrameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameDlg dialog

class CDlgDocFrameDlg : public CDialog
{
// Construction
public:
	CDlgDocFrameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDocFrameDlg)
	enum { IDD = IDD_INPUTDLG };
	double	m_dbX;
	double	m_dbY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDocFrameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDocFrameDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgDocFrameDLG_H__AA13F6BF_6E7C_4A68_9346_7094E9090CDD__INCLUDED_)
