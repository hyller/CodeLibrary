// KeyInputDoc.h : interface of the CKeyInputDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KEYINPUTDOC_H__D8D172ED_DA3A_4B28_BAB3_EF6D891221D3__INCLUDED_)
#define AFX_KEYINPUTDOC_H__D8D172ED_DA3A_4B28_BAB3_EF6D891221D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKeyInputDoc : public CDocument
{
protected: // create from serialization only
	CKeyInputDoc();
	DECLARE_DYNCREATE(CKeyInputDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyInputDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKeyInputDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKeyInputDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYINPUTDOC_H__D8D172ED_DA3A_4B28_BAB3_EF6D891221D3__INCLUDED_)
