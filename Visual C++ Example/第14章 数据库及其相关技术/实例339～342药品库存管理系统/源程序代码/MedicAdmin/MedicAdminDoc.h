// MedicAdminDoc.h : interface of the CMedicAdminDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEDICADMINDOC_H__AF090AB1_C003_4AD4_9DB4_929370F44B60__INCLUDED_)
#define AFX_MEDICADMINDOC_H__AF090AB1_C003_4AD4_9DB4_929370F44B60__INCLUDED_

#include "UserSet.h"	// Added by ClassView
#include "User.h"	// Added by ClassView
#include "MedicSet.h"	// Added by ClassView
#include "SaleSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMedicAdminDoc : public CDocument
{
protected: // create from serialization only
	CMedicAdminDoc();
	DECLARE_DYNCREATE(CMedicAdminDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMedicAdminDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void SetTitle(LPCTSTR lpszTitle);
	//}}AFX_VIRTUAL

// Implementation
public:
	//BOOL SetData();
	//CString userHeader[3];
	CSaleSet theSaleSet;
	CMedicSet theMedicSet;
	CUser theUser;
	CUserSet theUserSet;
	virtual ~CMedicAdminDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMedicAdminDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDICADMINDOC_H__AF090AB1_C003_4AD4_9DB4_929370F44B60__INCLUDED_)
