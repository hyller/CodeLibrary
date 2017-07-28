// SendMessageToProDlg.h : header file
//

#if !defined(AFX_SENDMESSAGETOPRODLG_H__58105E81_0BF8_491E_A587_F7C43A45E8C4__INCLUDED_)
#define AFX_SENDMESSAGETOPRODLG_H__58105E81_0BF8_491E_A587_F7C43A45E8C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSendMessageToProDlg dialog

class CSendMessageToProDlg : public CDialog
{
// Construction
public:
	CSendMessageToProDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSendMessageToProDlg)
	enum { IDD = IDD_SENDMESSAGETOPRO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendMessageToProDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSendMessageToProDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMessage1();
	afx_msg void OnMessage2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDMESSAGETOPRODLG_H__58105E81_0BF8_491E_A587_F7C43A45E8C4__INCLUDED_)
