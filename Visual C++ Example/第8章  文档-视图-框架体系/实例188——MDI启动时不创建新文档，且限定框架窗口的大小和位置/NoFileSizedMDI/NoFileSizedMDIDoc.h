// NoFileSizedMDIDoc.h : interface of the CNoFileSizedMDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOFILESIZEDMDIDOC_H__D6296B6E_6FC6_4783_90C8_905DC025F856__INCLUDED_)
#define AFX_NOFILESIZEDMDIDOC_H__D6296B6E_6FC6_4783_90C8_905DC025F856__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNoFileSizedMDIDoc : public CDocument
{
protected: // create from serialization only
	CNoFileSizedMDIDoc();
	DECLARE_DYNCREATE(CNoFileSizedMDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoFileSizedMDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNoFileSizedMDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNoFileSizedMDIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOFILESIZEDMDIDOC_H__D6296B6E_6FC6_4783_90C8_905DC025F856__INCLUDED_)
