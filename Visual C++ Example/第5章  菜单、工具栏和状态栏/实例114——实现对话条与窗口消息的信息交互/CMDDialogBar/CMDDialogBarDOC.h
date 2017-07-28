// CMDDialogBarDoc.h : interface of the CCMDDialogBarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMDDialogBarDOC_H__E2666730_5CA1_4CDA_9A2B_5EA69D54DCE3__INCLUDED_)
#define AFX_CMDDialogBarDOC_H__E2666730_5CA1_4CDA_9A2B_5EA69D54DCE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCMDDialogBarDoc : public CDocument
{
protected: // create from serialization only
	CCMDDialogBarDoc();
	DECLARE_DYNCREATE(CCMDDialogBarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDDialogBarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCMDDialogBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCMDDialogBarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDDialogBarDOC_H__E2666730_5CA1_4CDA_9A2B_5EA69D54DCE3__INCLUDED_)
