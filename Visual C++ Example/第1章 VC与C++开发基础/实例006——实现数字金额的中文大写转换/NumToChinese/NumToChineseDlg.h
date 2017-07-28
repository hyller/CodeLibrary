// NumToChineseDlg.h : header file
//

#if !defined(AFX_NUMTOCHINESEDLG_H__B43852A7_5972_486E_8C83_51509A20CA0D__INCLUDED_)
#define AFX_NUMTOCHINESEDLG_H__B43852A7_5972_486E_8C83_51509A20CA0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNumToChineseDlg dialog

class CNumToChineseDlg : public CDialog
{
// Construction
public:
	CNumToChineseDlg(CWnd* pParent = NULL);	// standard constructor
	CString ChineseCapitalMoney(double Num);
// Dialog Data
	//{{AFX_DATA(CNumToChineseDlg)
	enum { IDD = IDD_NUMTOCHINESE_DIALOG };
	double	m_dmoney;
	CString	m_strChineseCapital;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumToChineseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNumToChineseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTrans();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMTOCHINESEDLG_H__B43852A7_5972_486E_8C83_51509A20CA0D__INCLUDED_)
