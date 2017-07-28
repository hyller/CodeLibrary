#if !defined(AFX_OLEEDITCTL_H__53527F6B_9A66_4CE7_BBEE_5FC9E1475645__INCLUDED_)
#define AFX_OLEEDITCTL_H__53527F6B_9A66_4CE7_BBEE_5FC9E1475645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// OleEditCtl.h : Declaration of the COleEditCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl : See OleEditCtl.cpp for implementation.

class COleEditCtrl : public COleControl
{
	DECLARE_DYNCREATE(COleEditCtrl)

// Constructor
public:
	COleEditCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleEditCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~COleEditCtrl();

	DECLARE_OLECREATE_EX(COleEditCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(COleEditCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(COleEditCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(COleEditCtrl)		// Type name and misc status

	// Subclassed control support
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// Message maps
	//{{AFX_MSG(COleEditCtrl)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(COleEditCtrl)
	BOOL m_bNumbers;
	afx_msg void OnBNumbersChanged();
	BOOL m_bText;
	afx_msg void OnBTextChanged();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(COleEditCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(COleEditCtrl)
	dispidBNumbers = 1L,
	dispidBText = 2L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEEDITCTL_H__53527F6B_9A66_4CE7_BBEE_5FC9E1475645__INCLUDED)
