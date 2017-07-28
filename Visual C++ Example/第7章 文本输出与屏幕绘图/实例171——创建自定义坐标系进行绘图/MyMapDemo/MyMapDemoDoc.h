// MyMapDemoDoc.h : interface of the CMyMapDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMAPDEMODOC_H__3B194F70_732D_42D0_8A12_2A0D4A3B684F__INCLUDED_)
#define AFX_MYMAPDEMODOC_H__3B194F70_732D_42D0_8A12_2A0D4A3B684F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyMapDemoDoc : public CDocument
{
protected: // create from serialization only
	CMyMapDemoDoc();
	DECLARE_DYNCREATE(CMyMapDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMapDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyMapDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyMapDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMAPDEMODOC_H__3B194F70_732D_42D0_8A12_2A0D4A3B684F__INCLUDED_)
