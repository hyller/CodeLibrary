// MCIWavPlayDlg.h : header file
//

#if !defined(AFX_MCIWavPlayDLG_H__FC4FF8C9_962E_4A66_BA47_8ED57BACA600__INCLUDED_)
#define AFX_MCIWavPlayDLG_H__FC4FF8C9_962E_4A66_BA47_8ED57BACA600__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyMCIWave.h"
#include "ExListBox.h"

/////////////////////////////////////////////////////////////////////////////
// CMCIWavPlayDlg dialog

class CMCIWavPlayDlg : public CDialog
{
// Construction
public:
	CMCIWavPlayDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMCIWavPlayDlg)
	enum { IDD = IDD_MCIWavPlay_DIALOG };
	CExListBox	m_List;
	CString	m_strbits;
	CString	m_strChannel;
	CString	m_strname;
	CString	m_strtime;
	CString	m_strSample;
	CString	m_strstatus;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMCIWavPlayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMyMCIWave m_MyMCIWave;

	// Generated message map functions
	//{{AFX_MSG(CMCIWavPlayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenwav();
	afx_msg void OnPlaywav();
	afx_msg void OnRecordwav();
	afx_msg void OnSavewav();
	afx_msg void OnStopwav();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCIWavPlayDLG_H__FC4FF8C9_962E_4A66_BA47_8ED57BACA600__INCLUDED_)
