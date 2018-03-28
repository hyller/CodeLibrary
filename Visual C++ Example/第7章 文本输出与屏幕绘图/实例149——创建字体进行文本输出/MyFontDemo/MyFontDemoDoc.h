// MyFontDemoDoc.h : interface of the CMyFontDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFONTDEMODOC_H__2EA4F820_424C_4FD7_9D98_81289E3CCD05__INCLUDED_)
#define AFX_MYFONTDEMODOC_H__2EA4F820_424C_4FD7_9D98_81289E3CCD05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyFontDemoDoc : public CDocument
{
protected: // create from serialization only
	CMyFontDemoDoc();
	DECLARE_DYNCREATE(CMyFontDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFontDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyFontDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyFontDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFONTDEMODOC_H__2EA4F820_424C_4FD7_9D98_81289E3CCD05__INCLUDED_)
