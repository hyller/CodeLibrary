// BeepVoiceDlg.h : header file
//

#if !defined(AFX_BEEPVOICEDLG_H__FDFFA2DB_05C4_4DAF_A3F2_7B429B6241A7__INCLUDED_)
#define AFX_BEEPVOICEDLG_H__FDFFA2DB_05C4_4DAF_A3F2_7B429B6241A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBeepVoiceDlg dialog

class CBeepVoiceDlg : public CDialog
{
// Construction
public:
	CBeepVoiceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBeepVoiceDlg)
	enum { IDD = IDD_BEEPVOICE_DIALOG };
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBeepVoiceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBeepVoiceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BEEPVOICEDLG_H__FDFFA2DB_05C4_4DAF_A3F2_7B429B6241A7__INCLUDED_)
