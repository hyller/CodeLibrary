// FontDlgDemoDlg.h : header file
//

#if !defined(AFX_FONTDLGDEMODLG_H__17F4AC38_8EBD_43AD_A850_0C32AF721A36__INCLUDED_)
#define AFX_FONTDLGDEMODLG_H__17F4AC38_8EBD_43AD_A850_0C32AF721A36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFontDlgDemoDlg dialog

class CFontDlgDemoDlg : public CDialog
{
// Construction
public:
	CFontDlgDemoDlg(CWnd* pParent = NULL);	// standard constructor
	LOGFONT fnt;												//字体结构
	COLORREF fntColor;											//字体颜色信息
// Dialog Data
	//{{AFX_DATA(CFontDlgDemoDlg)
	enum { IDD = IDD_FONTDLGDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontDlgDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFontDlgDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTDLGDEMODLG_H__17F4AC38_8EBD_43AD_A850_0C32AF721A36__INCLUDED_)
