// MoveAnyWhereDlg.h : header file
//

#if !defined(AFX_MOVEANYWHEREDLG_H__58429040_6255_4CD3_8F0D_AEF3FC4CA77B__INCLUDED_)
#define AFX_MOVEANYWHEREDLG_H__58429040_6255_4CD3_8F0D_AEF3FC4CA77B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMoveAnyWhereDlg dialog

class CMoveAnyWhereDlg : public CDialog
{
// Construction
public:
	CMoveAnyWhereDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMoveAnyWhereDlg)
	enum { IDD = IDD_MOVEANYWHERE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoveAnyWhereDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMoveAnyWhereDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVEANYWHEREDLG_H__58429040_6255_4CD3_8F0D_AEF3FC4CA77B__INCLUDED_)
