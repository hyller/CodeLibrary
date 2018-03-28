// ListButtonToolBarDoc.h : interface of the CListButtonToolBarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTBUTTONTOOLBARDOC_H__85225B9C_865D_47DD_9C0D_2DAB0A7D9B26__INCLUDED_)
#define AFX_LISTBUTTONTOOLBARDOC_H__85225B9C_865D_47DD_9C0D_2DAB0A7D9B26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CListButtonToolBarDoc : public CDocument
{
protected: // create from serialization only
	CListButtonToolBarDoc();
	DECLARE_DYNCREATE(CListButtonToolBarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListButtonToolBarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListButtonToolBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CListButtonToolBarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBUTTONTOOLBARDOC_H__85225B9C_865D_47DD_9C0D_2DAB0A7D9B26__INCLUDED_)
