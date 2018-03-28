// EnumFontsDemoDlg.h : header file
//

#if !defined(AFX_ENUMFONTSDEMODLG_H__5F4405C6_6E28_40ED_AF28_8867BD140CB4__INCLUDED_)
#define AFX_ENUMFONTSDEMODLG_H__5F4405C6_6E28_40ED_AF28_8867BD140CB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEnumFontsDemoDlg dialog

class CEnumFontsDemoDlg : public CDialog
{
// Construction
public:
	CEnumFontsDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEnumFontsDemoDlg)
	enum { IDD = IDD_ENUMFONTSDEMO_DIALOG };
	CListBox	m_ctlList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumFontsDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEnumFontsDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetfonts();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMFONTSDEMODLG_H__5F4405C6_6E28_40ED_AF28_8867BD140CB4__INCLUDED_)
