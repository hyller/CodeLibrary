#if !defined(AFX_QUESTCONNECT_H__6D167F4C_EF11_4164_B862_67812C01DE3E__INCLUDED_)
#define AFX_QUESTCONNECT_H__6D167F4C_EF11_4164_B862_67812C01DE3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QuestConnect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuestConnect dialog

class CQuestConnect : public CDialog
{
// Construction
public:
	CQuestConnect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQuestConnect)
	enum { IDD = IDD_REQUEST };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuestConnect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQuestConnect)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESTCONNECT_H__6D167F4C_EF11_4164_B862_67812C01DE3E__INCLUDED_)
