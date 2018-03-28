// DcDemoDoc.h : interface of the CDcDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCDEMODOC_H__A9275211_21FB_474E_BEC9_E6274BF478CE__INCLUDED_)
#define AFX_DCDEMODOC_H__A9275211_21FB_474E_BEC9_E6274BF478CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDcDemoDoc : public CDocument
{
protected: // create from serialization only
	CDcDemoDoc();
	DECLARE_DYNCREATE(CDcDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDcDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDcDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDcDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DCDEMODOC_H__A9275211_21FB_474E_BEC9_E6274BF478CE__INCLUDED_)
