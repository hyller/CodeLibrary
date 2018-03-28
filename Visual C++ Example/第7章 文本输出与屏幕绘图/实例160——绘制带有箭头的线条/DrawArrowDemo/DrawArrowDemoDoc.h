// DrawArrowDemoDoc.h : interface of the CDrawArrowDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWARROWDEMODOC_H__6920F5B0_DAE4_4319_8E5A_BCF39A22C528__INCLUDED_)
#define AFX_DRAWARROWDEMODOC_H__6920F5B0_DAE4_4319_8E5A_BCF39A22C528__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawArrowDemoDoc : public CDocument
{
protected: // create from serialization only
	CDrawArrowDemoDoc();
	DECLARE_DYNCREATE(CDrawArrowDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawArrowDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawArrowDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawArrowDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWARROWDEMODOC_H__6920F5B0_DAE4_4319_8E5A_BCF39A22C528__INCLUDED_)
