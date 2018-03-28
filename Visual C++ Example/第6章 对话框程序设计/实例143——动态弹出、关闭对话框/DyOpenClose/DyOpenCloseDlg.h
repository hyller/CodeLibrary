// DyOpenCloseDlg.h : header file
//

#if !defined(AFX_DYOPENCLOSEDLG_H__106EAA2C_67E8_491D_A90F_7CB8D4548229__INCLUDED_)
#define AFX_DYOPENCLOSEDLG_H__106EAA2C_67E8_491D_A90F_7CB8D4548229__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDyOpenCloseDlg dialog

class CDyOpenCloseDlg : public CDialog
{
// Construction
public:
	CDyOpenCloseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDyOpenCloseDlg)
	enum { IDD = IDD_DYOPENCLOSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDyOpenCloseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int m_nWidth,m_nHeight;//对话框窗口尺寸
	int m_nDx,m_nDy;//打开对话框时，对话框展开的步进量
	int m_nDx1,m_nDy1;//关闭对话框时，对话框收缩的步进量
	// Generated message map functions
	//{{AFX_MSG(CDyOpenCloseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYOPENCLOSEDLG_H__106EAA2C_67E8_491D_A90F_7CB8D4548229__INCLUDED_)
