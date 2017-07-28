// RgnDemoDoc.h : interface of the CRgnDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGNDEMODOC_H__28B4D361_C9FB_42BB_BD50_FCACC204C9AB__INCLUDED_)
#define AFX_RGNDEMODOC_H__28B4D361_C9FB_42BB_BD50_FCACC204C9AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRgnDemoDoc : public CDocument
{
protected: // create from serialization only
	CRgnDemoDoc();
	DECLARE_DYNCREATE(CRgnDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRgnDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRgnDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRgnDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGNDEMODOC_H__28B4D361_C9FB_42BB_BD50_FCACC204C9AB__INCLUDED_)
