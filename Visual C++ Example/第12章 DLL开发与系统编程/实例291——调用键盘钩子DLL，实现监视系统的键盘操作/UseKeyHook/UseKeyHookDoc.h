// UseKeyHookDoc.h : interface of the CUseKeyHookDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USEKEYHOOKDOC_H__251F201F_36D9_40E6_9180_BFF6ECFB42FC__INCLUDED_)
#define AFX_USEKEYHOOKDOC_H__251F201F_36D9_40E6_9180_BFF6ECFB42FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUseKeyHookDoc : public CDocument
{
protected: // create from serialization only
	CUseKeyHookDoc();
	DECLARE_DYNCREATE(CUseKeyHookDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseKeyHookDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseKeyHookDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseKeyHookDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEKEYHOOKDOC_H__251F201F_36D9_40E6_9180_BFF6ECFB42FC__INCLUDED_)
