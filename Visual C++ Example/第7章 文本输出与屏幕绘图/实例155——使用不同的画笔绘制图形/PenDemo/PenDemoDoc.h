// PenDemoDoc.h : interface of the CPenDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PENDEMODOC_H__68052203_7116_43EC_BAE7_30155B3762D7__INCLUDED_)
#define AFX_PENDEMODOC_H__68052203_7116_43EC_BAE7_30155B3762D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPenDemoDoc : public CDocument
{
protected: // create from serialization only
	CPenDemoDoc();
	DECLARE_DYNCREATE(CPenDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPenDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPenDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPenDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PENDEMODOC_H__68052203_7116_43EC_BAE7_30155B3762D7__INCLUDED_)
