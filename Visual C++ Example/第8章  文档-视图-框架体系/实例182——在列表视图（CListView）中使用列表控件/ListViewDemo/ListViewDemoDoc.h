// ListViewDemoDoc.h : interface of the CListViewDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTVIEWDEMODOC_H__554C2B99_EBD4_4CB1_9DB3_DE66947AA5EA__INCLUDED_)
#define AFX_LISTVIEWDEMODOC_H__554C2B99_EBD4_4CB1_9DB3_DE66947AA5EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CListViewDemoDoc : public CDocument
{
protected: // create from serialization only
	CListViewDemoDoc();
	DECLARE_DYNCREATE(CListViewDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListViewDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListViewDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CListViewDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTVIEWDEMODOC_H__554C2B99_EBD4_4CB1_9DB3_DE66947AA5EA__INCLUDED_)
