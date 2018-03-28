// BaseDocViewDemo1Doc.h : interface of the CBaseDocViewDemo1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEDOCVIEWDEMO1DOC_H__68B5D037_AA49_4EC1_8300_1331BB89C19D__INCLUDED_)
#define AFX_BASEDOCVIEWDEMO1DOC_H__68B5D037_AA49_4EC1_8300_1331BB89C19D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseDocViewDemo1Doc : public CDocument
{
protected: // create from serialization only
	CBaseDocViewDemo1Doc();
	DECLARE_DYNCREATE(CBaseDocViewDemo1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDocViewDemo1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBaseDocViewDemo1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseDocViewDemo1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEDOCVIEWDEMO1DOC_H__68B5D037_AA49_4EC1_8300_1331BB89C19D__INCLUDED_)
