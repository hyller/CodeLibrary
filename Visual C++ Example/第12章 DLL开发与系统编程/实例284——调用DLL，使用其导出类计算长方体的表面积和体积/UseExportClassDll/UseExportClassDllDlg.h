// UseExportClassDllDlg.h : header file
//

#if !defined(AFX_USEEXPORTCLASSDLLDLG_H__CBB99B8D_4E9D_4A98_9A95_AF62F2514F11__INCLUDED_)
#define AFX_USEEXPORTCLASSDLLDLG_H__CBB99B8D_4E9D_4A98_9A95_AF62F2514F11__INCLUDED_
#include "AreaVolumnClass.h"												//包含头文件
#pragma comment(lib,"ExportClassDll.lib")									//隐式导入DLL

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseExportClassDllDlg dialog

class CUseExportClassDllDlg : public CDialog
{
// Construction
public:
	CUseExportClassDllDlg(CWnd* pParent = NULL);	// standard constructor
	AreaVolumnClass MyClass;
// Dialog Data
	//{{AFX_DATA(CUseExportClassDllDlg)
	enum { IDD = IDD_USEEXPORTCLASSDLL_DIALOG };
	double	m_Lenth;
	double	m_Width;
	double	m_Height;
	double	m_SurfaceArea;
	double	m_Volumn;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseExportClassDllDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseExportClassDllDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEEXPORTCLASSDLLDLG_H__CBB99B8D_4E9D_4A98_9A95_AF62F2514F11__INCLUDED_)
