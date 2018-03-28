// ScrollTextDlg.h : header file
//

#if !defined(AFX_SCROLLTEXTDLG_H__D6908FAF_5785_4BB4_A678_BE30B894BF3A__INCLUDED_)
#define AFX_SCROLLTEXTDLG_H__D6908FAF_5785_4BB4_A678_BE30B894BF3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScrollTextDlg dialog

class CScrollTextDlg : public CDialog
{
// Construction
public:
	CScrollTextDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScrollTextDlg)
	enum { IDD = IDD_SCROLLTEXT_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollTextDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CString str;//字幕文本
	int WidthX;//文本输出的水平位置
	TEXTMETRIC tm; 	//字体结构
	// Generated message map functions
	//{{AFX_MSG(CScrollTextDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLTEXTDLG_H__D6908FAF_5785_4BB4_A678_BE30B894BF3A__INCLUDED_)
