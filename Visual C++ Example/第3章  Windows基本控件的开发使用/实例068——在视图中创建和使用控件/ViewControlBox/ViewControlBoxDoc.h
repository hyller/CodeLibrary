// ViewControlBoxDoc.h : interface of the CViewControlBoxDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWCONTROLBOXDOC_H__786D6209_4FED_472A_9181_28A2ADA5BDE9__INCLUDED_)
#define AFX_VIEWCONTROLBOXDOC_H__786D6209_4FED_472A_9181_28A2ADA5BDE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CViewControlBoxDoc : public CDocument
{
protected: // create from serialization only
	CViewControlBoxDoc();
	DECLARE_DYNCREATE(CViewControlBoxDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewControlBoxDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CViewControlBoxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CViewControlBoxDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWCONTROLBOXDOC_H__786D6209_4FED_472A_9181_28A2ADA5BDE9__INCLUDED_)
