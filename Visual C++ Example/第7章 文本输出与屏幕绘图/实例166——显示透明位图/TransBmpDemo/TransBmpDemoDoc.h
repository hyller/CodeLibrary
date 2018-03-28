// TransBmpDemoDoc.h : interface of the CTransBmpDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSBMPDEMODOC_H__E67FBCAB_F956_4EAD_A64F_BD16771834E4__INCLUDED_)
#define AFX_TRANSBMPDEMODOC_H__E67FBCAB_F956_4EAD_A64F_BD16771834E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTransBmpDemoDoc : public CDocument
{
protected: // create from serialization only
	CTransBmpDemoDoc();
	DECLARE_DYNCREATE(CTransBmpDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransBmpDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTransBmpDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTransBmpDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSBMPDEMODOC_H__E67FBCAB_F956_4EAD_A64F_BD16771834E4__INCLUDED_)
