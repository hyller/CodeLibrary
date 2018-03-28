// DrawStaticDemoDlg.h : header file
//

#if !defined(AFX_DRAWSTATICDEMODLG_H__5AA515D7_7883_4FD3_BEDC_6C6BFF45BE0A__INCLUDED_)
#define AFX_DRAWSTATICDEMODLG_H__5AA515D7_7883_4FD3_BEDC_6C6BFF45BE0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDrawStaticDemoDlg dialog

class CDrawStaticDemoDlg : public CDialog
{
// Construction
public:
	CDrawStaticDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDrawStaticDemoDlg)
	enum { IDD = IDD_DRAWSTATICDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawStaticDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDrawStaticDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStaticDraw();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWSTATICDEMODLG_H__5AA515D7_7883_4FD3_BEDC_6C6BFF45BE0A__INCLUDED_)
