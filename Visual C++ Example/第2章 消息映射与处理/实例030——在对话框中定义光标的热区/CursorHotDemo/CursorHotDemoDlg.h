// CursorHotDemoDlg.h : header file
//

#if !defined(AFX_CURSORHOTDEMODLG_H__50BE64FD_8C8B_439F_B3C4_69CBB95C102B__INCLUDED_)
#define AFX_CURSORHOTDEMODLG_H__50BE64FD_8C8B_439F_B3C4_69CBB95C102B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCursorHotDemoDlg dialog

class CCursorHotDemoDlg : public CDialog
{
// Construction
public:
	CCursorHotDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCursorHotDemoDlg)
	enum { IDD = IDD_CURSORHOTDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCursorHotDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCursorHotDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURSORHOTDEMODLG_H__50BE64FD_8C8B_439F_B3C4_69CBB95C102B__INCLUDED_)
