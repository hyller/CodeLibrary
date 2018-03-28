// SolidFontDemoDoc.h : interface of the CSolidFontDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOLIDFONTDEMODOC_H__D8486DDE_7CA6_454F_9C55_31E8FCC14203__INCLUDED_)
#define AFX_SOLIDFONTDEMODOC_H__D8486DDE_7CA6_454F_9C55_31E8FCC14203__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSolidFontDemoDoc : public CDocument
{
protected: // create from serialization only
	CSolidFontDemoDoc();
	DECLARE_DYNCREATE(CSolidFontDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSolidFontDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSolidFontDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSolidFontDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOLIDFONTDEMODOC_H__D8486DDE_7CA6_454F_9C55_31E8FCC14203__INCLUDED_)
