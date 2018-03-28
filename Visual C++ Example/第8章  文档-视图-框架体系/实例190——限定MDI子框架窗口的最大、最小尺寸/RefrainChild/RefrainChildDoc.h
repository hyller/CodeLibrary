// RefrainChildDoc.h : interface of the CRefrainChildDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_REFRAINCHILDDOC_H__DD174D9C_96ED_4394_8D4D_124CAE1A5E60__INCLUDED_)
#define AFX_REFRAINCHILDDOC_H__DD174D9C_96ED_4394_8D4D_124CAE1A5E60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRefrainChildDoc : public CDocument
{
protected: // create from serialization only
	CRefrainChildDoc();
	DECLARE_DYNCREATE(CRefrainChildDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRefrainChildDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRefrainChildDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRefrainChildDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REFRAINCHILDDOC_H__DD174D9C_96ED_4394_8D4D_124CAE1A5E60__INCLUDED_)
