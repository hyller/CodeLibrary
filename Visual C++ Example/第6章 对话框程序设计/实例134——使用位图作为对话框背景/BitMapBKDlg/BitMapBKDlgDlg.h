// BitMapBKDlgDlg.h : header file
//

#if !defined(AFX_BITMAPBKDLGDLG_H__12FD8D0D_E440_4DA9_AD95_BA64BE46162D__INCLUDED_)
#define AFX_BITMAPBKDLGDLG_H__12FD8D0D_E440_4DA9_AD95_BA64BE46162D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBitMapBKDlgDlg dialog

class CBitMapBKDlgDlg : public CDialog
{
// Construction
public:
	CBitMapBKDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBitMapBKDlgDlg)
	enum { IDD = IDD_BITMAPBKDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitMapBKDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBitMapBKDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush m_BKBrush;//»­Ë¢
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPBKDLGDLG_H__12FD8D0D_E440_4DA9_AD95_BA64BE46162D__INCLUDED_)
