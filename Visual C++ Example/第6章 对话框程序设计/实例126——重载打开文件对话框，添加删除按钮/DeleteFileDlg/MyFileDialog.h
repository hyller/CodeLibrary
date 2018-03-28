#if !defined(AFX_MYFILEDIALOG_H__DF2E1ECB_35D4_47FF_B8B7_D7E009801635__INCLUDED_)
#define AFX_MYFILEDIALOG_H__DF2E1ECB_35D4_47FF_B8B7_D7E009801635__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyFileDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyFileDialog dialog

class CMyFileDialog : public CFileDialog
{
	DECLARE_DYNAMIC(CMyFileDialog)

public:
	CMyFileDialog();

protected:
	//{{AFX_MSG(CMyFileDialog)
	afx_msg void OnDletefile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFILEDIALOG_H__DF2E1ECB_35D4_47FF_B8B7_D7E009801635__INCLUDED_)
