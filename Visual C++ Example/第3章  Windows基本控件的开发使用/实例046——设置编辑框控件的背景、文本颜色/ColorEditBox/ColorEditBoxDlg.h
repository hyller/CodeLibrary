// ColorEditBoxDlg.h : header file
//

#if !defined(AFX_COLOREDITBOXDLG_H__FCF631E7_3BFC_4CFB_A590_8E80A7617423__INCLUDED_)
#define AFX_COLOREDITBOXDLG_H__FCF631E7_3BFC_4CFB_A590_8E80A7617423__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CColorEditBoxDlg dialog

class CColorEditBoxDlg : public CDialog
{
// Construction
public:
	CColorEditBoxDlg(CWnd* pParent = NULL);	// standard constructor
	CBrush m_redbrush,m_bluebrush;//定义画刷
	COLORREF m_redcolor,m_bluecolor,m_textcolor;//定义颜色结构


// Dialog Data
	//{{AFX_DATA(CColorEditBoxDlg)
	enum { IDD = IDD_COLOREDITBOX_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorEditBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CColorEditBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREDITBOXDLG_H__FCF631E7_3BFC_4CFB_A590_8E80A7617423__INCLUDED_)
