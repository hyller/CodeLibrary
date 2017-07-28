// StaticBMPMovieDlg.h : header file
//

#if !defined(AFX_STATICBMPMOVIEDLG_H__EC6E2B8C_9CC9_43BA_BC60_BA54F82618DF__INCLUDED_)
#define AFX_STATICBMPMOVIEDLG_H__EC6E2B8C_9CC9_43BA_BC60_BA54F82618DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStaticBMPMovieDlg dialog

class CStaticBMPMovieDlg : public CDialog
{
// Construction
public:
	CStaticBMPMovieDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStaticBMPMovieDlg)
	enum { IDD = IDD_STATICBMPMOVIE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticBMPMovieDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CBitmap *m_pBmp[6];//位图指针数组
	BITMAP bs;//BITMAP结构变量
	int m_nCurFrame;//动画的当前帧
	// Generated message map functions
	//{{AFX_MSG(CStaticBMPMovieDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStar();
	afx_msg void OnStop();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICBMPMOVIEDLG_H__EC6E2B8C_9CC9_43BA_BC60_BA54F82618DF__INCLUDED_)
