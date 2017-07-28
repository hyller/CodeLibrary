// ADODateGridDoc.h : interface of the CADODateGridDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADODATEGRIDDOC_H__6D31B7CD_E88D_426F_919E_206DE03E7807__INCLUDED_)
#define AFX_ADODATEGRIDDOC_H__6D31B7CD_E88D_426F_919E_206DE03E7807__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CADODateGridDoc : public CDocument
{
protected: // create from serialization only
	CADODateGridDoc();
	DECLARE_DYNCREATE(CADODateGridDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODateGridDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CADODateGridDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CADODateGridDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATEGRIDDOC_H__6D31B7CD_E88D_426F_919E_206DE03E7807__INCLUDED_)
