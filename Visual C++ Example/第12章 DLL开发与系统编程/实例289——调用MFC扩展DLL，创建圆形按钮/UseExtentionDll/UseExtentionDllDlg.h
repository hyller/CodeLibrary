// UseExtentionDllDlg.h : header file
//

#if !defined(AFX_USEEXTENTIONDLLDLG_H__014CF693_C4F9_4A5A_9670_9BF3D5E50685__INCLUDED_)
#define AFX_USEEXTENTIONDLLDLG_H__014CF693_C4F9_4A5A_9670_9BF3D5E50685__INCLUDED_
#include "ROUNDBUTTON.H"										//导出类的头文件
#pragma comment(lib,"ExtensionDll.lib")								//隐式链接DLL
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseExtentionDllDlg dialog

class CUseExtentionDllDlg : public CDialog
{
// Construction
public:
	CUseExtentionDllDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUseExtentionDllDlg)
	enum { IDD = IDD_USEEXTENTIONDLL_DIALOG };
	CRoundButton	m_ctlButton2;
	CRoundButton	m_ctlButton1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseExtentionDllDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseExtentionDllDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEEXTENTIONDLLDLG_H__014CF693_C4F9_4A5A_9670_9BF3D5E50685__INCLUDED_)
