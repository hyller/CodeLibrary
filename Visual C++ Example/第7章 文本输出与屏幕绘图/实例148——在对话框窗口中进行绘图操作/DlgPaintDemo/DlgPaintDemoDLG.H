// DlgPaintDemoDlg.h : header file
//

#if !defined(AFX_DlgPaintDemoDLG_H__9B5AC947_B5B3_11D6_BA91_0000B48A08B1__INCLUDED_)
#define AFX_DlgPaintDemoDLG_H__9B5AC947_B5B3_11D6_BA91_0000B48A08B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgPaintDemoDlg dialog


class CDlgPaintDemoDlg : public CDialog
{
// Construction
public:
	void DrawElement();
	CDlgPaintDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPaintDemoDlg)
	enum { IDD = IDD_DlgPaintDemo_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPaintDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgPaintDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDrawgraphy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CRect conRect;
	BOOL b_draw;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgPaintDemoDLG_H__9B5AC947_B5B3_11D6_BA91_0000B48A08B1__INCLUDED_)
